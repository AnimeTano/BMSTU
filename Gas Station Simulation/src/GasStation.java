import java.util.*;

public class GasStation {
    private Config config;
    private Statistics stat;
    private List<FuelPump> pumps;
    private Queue<Car> queue;
    private double fuelReserve;
    private double maxFuelCapacity;

    public GasStation(Config config, Statistics stat) {
        this.config = config;
        this.stat = stat;
        this.pumps = new ArrayList<>();
        this.queue = new LinkedList<>();
        this.fuelReserve = config.getInitialFuel();
        this.maxFuelCapacity = config.getMaxFuelCapacity();

        stat.updateMinFuelReserve(fuelReserve);

        for (int i = 0; i < config.getInitialPumps(); i++) {
            FuelPump p = new FuelPump(config.getDefaultFlowRate(), 0.0);
            pumps.add(p);
            stat.pumpOpenRecord(p.getId(), 0.0);
        }
    }

    public FuelPump freePump() {
        for (FuelPump obj : pumps) {
            if (!obj.isBusy()) return obj;
        }
        return null;
    }

    public void addToQueue(Car car) {
        queue.add(car);
        stat.updateQueueLength(queue.size());
    }

    public void addPump(double cur) {
        if (pumps.size() >= config.getMaxPumps()) return;

        FuelPump newPump = new FuelPump(config.getDefaultFlowRate(), cur);
        pumps.add(newPump);
        stat.pumpOpenRecord(newPump.getId(), cur);
        stat.incrementExpansions();

        serveNextFromQueue(newPump, cur);
    }

    public void updateFuelCapacity(double amount) {
        if ((amount + fuelReserve) >= maxFuelCapacity) {
            fuelReserve = maxFuelCapacity;
        } else {
            fuelReserve = fuelReserve + amount;
        }
        stat.updateMinFuelReserve(fuelReserve);
    }

    public void deliverFuel(double amount) {
        updateFuelCapacity(amount);
    }

    public void recordFuelBeforeDelivery() {
        stat.deliveryOccurred(fuelReserve);
    }

    public boolean hasEnoughFuel(Car car) {
        return fuelReserve >= car.getDesiredFuel();
    }

    public void releasePump(FuelPump pump, double cur) {
        pump.freePump();
        serveNextFromQueue(pump, cur);
    }

    public boolean serveNextFromQueue(FuelPump pump, double cur) {
       while (!queue.isEmpty()) {
           Car nextCar = queue.peek();

           if (!hasEnoughFuel(nextCar)) {
               queue.poll();
               stat.refused();
               continue;
           }
           queue.poll();
           servingCar(pump, nextCar, cur);
           return true;
       }
       return false;
    }

    public void tryServeAllPumps(double cur) {
        for (FuelPump obj : pumps) {
            if (!obj.isBusy()) {
                serveNextFromQueue(obj, cur);
            }
        }
    }

    public void servingCar(FuelPump pump, Car car, double cur) {
        fuelReserve -= car.getDesiredFuel();
        stat.updateMinFuelReserve(fuelReserve);
        stat.served(cur - car.getArrivalTime(), car.getDesiredFuel() / pump.getFlowRate());
        stat.pumpServiceRecord(pump.getId(), car.getDesiredFuel() / pump.getFlowRate());
        pump.serviceMaintenance(car, cur);
    }

    public List<FuelPump> getPumps() { return pumps; }
    public Queue<Car> getQueue() { return queue; }
    public double getFuelReserve() { return fuelReserve; }
}