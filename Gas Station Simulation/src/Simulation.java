import java.util.*;

public class Simulation {
    private final Config config;
    private final GasStation station;
    private final CarGenerator carGenerator;
    private final Statistics stats;
    private final PriorityQueue<Event> eventQueue;
    private double currentTime;
    private final double simEndTime;
    private boolean expansionScheduled = false;

    public Simulation(Config config, GasStation station, CarGenerator carGenerator, Statistics stats) {
        this.config = config;
        this.station = station;
        this.carGenerator = carGenerator;
        this.stats = stats;
        this.eventQueue = new PriorityQueue<>();
        this.currentTime = 0.0;
        this.simEndTime = config.getSimulationDays() * 24 * 60;

        // Начальные события
        eventQueue.add(new Event("CAR_ARRIVAL", carGenerator.generateNextInterval(0)));
        eventQueue.add(new Event("DELIVERY_START", config.getDeliveryInterval() * 60));
    }

    public void run() {
        while (!eventQueue.isEmpty()) {
            Event e = eventQueue.poll();
            currentTime = e.getTime();
            if (currentTime > simEndTime) break;

            switch (e.getType()) {
                case "CAR_ARRIVAL": {
                    Car car = carGenerator.generateCar(currentTime);
                    stats.arrived();

                    if (!station.hasEnoughFuel(car)) {
                        stats.refused();
                    } else {
                        FuelPump free = station.freePump();
                        if (free != null) {
                            station.servingCar(free, car, currentTime);
                            eventQueue.add(new Event("SERVICE_END", free, car.getEndServiceTime()));
                        } else {
                            station.addToQueue(car);
                        }
                    }

                    double nextArrival = currentTime + carGenerator.generateNextInterval(currentTime);
                    if (nextArrival <= simEndTime)
                        eventQueue.add(new Event("CAR_ARRIVAL", nextArrival));

                    checkExpansionByQueue();
                    break;
                }

                case "SERVICE_END": {
                    FuelPump pump = (FuelPump) e.getData();
                    Car car = pump.getCurrentCar();

                    if (car == null) break;

                    double waitTime = car.getStartServiceTime() - car.getArrivalTime();
                    if (waitTime > config.getQueueThreshold()) {
                        scheduleExpansion();
                    }

                    pump.addServiceTime(car.getDesiredFuel() / pump.getFlowRate());
                    station.releasePump(pump, currentTime);

                    if (pump.isBusy()) {
                        eventQueue.add(new Event("SERVICE_END", pump, pump.getCurrentCar().getEndServiceTime()));
                    }

                    checkExpansionByQueue();
                    break;
                }

                case "DELIVERY_START": {
                    double endTime = currentTime + config.getDeliveryDuration();
                    eventQueue.add(new Event("DELIVERY_END", endTime));
                    break;
                }

                case "DELIVERY_END": {
                    station.recordFuelBeforeDelivery();
                    station.deliverFuel(config.getDeliveryVolume());
                    station.tryServeAllPumps(currentTime);

                    double nextStart = currentTime + config.getDeliveryInterval() * 60;
                    if (nextStart <= simEndTime)
                        eventQueue.add(new Event("DELIVERY_START", nextStart));
                    break;
                }

                case "PUMP_OPEN": {
                    expansionScheduled = false;
                    station.addPump(currentTime);

                    List<FuelPump> pumps = station.getPumps();
                    if (!pumps.isEmpty()) {
                        FuelPump newPump = pumps.get(pumps.size() - 1);
                        if (newPump.isBusy()) {
                            eventQueue.add(new Event("SERVICE_END", newPump, newPump.getCurrentCar().getEndServiceTime()));
                        }
                    }

                    checkExpansionByQueue();
                    break;
                }
            }
        }
        stats.printReport(simEndTime);
    }

    private void checkExpansionByQueue() {
        if (expansionScheduled) return;
        if (station.getPumps().size() >= config.getMaxPumps()) return;

        for (Car c : station.getQueue()) {
            if (currentTime - c.getArrivalTime() > config.getQueueThreshold()) {
                scheduleExpansion();
                break;
            }
        }
    }

    private void scheduleExpansion() {
        if (expansionScheduled) return;
        if (station.getPumps().size() >= config.getMaxPumps()) return;

        double openTime = currentTime + config.getExpansionDelay() * 24 * 60;
        if (openTime <= simEndTime) {
            eventQueue.add(new Event("PUMP_OPEN", openTime));
            expansionScheduled = true;
        }
    }
}