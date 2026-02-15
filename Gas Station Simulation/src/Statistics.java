import java.util.*;


public class Statistics {
    private int totalArrived = 0;
    private int totalServed = 0;
    private int totalRefused = 0;
    private double totalWaitTime = 0.0;
    private double maxWaitTime = 0.0;
    private double totalServiceTime = 0.0;
    private int maxQueueLength = 0;
    private int expansionsCount = 0;
    private int deliveriesCount = 0;
    private double totalFuelBeforeDeliveries = 0.0;
    private double minFuelReserve = Double.MAX_VALUE;
    private Map<Integer, Double> pumpServiceTime = new HashMap<>();
    private Map<Integer, Double> pumpOpenTime = new HashMap<>();

    public void arrived() { totalArrived++; }
    public void refused() { totalRefused++; }

    public void incrementExpansions() {
        expansionsCount++;
    }

    public void served(double waitTime, double serviceTime) {
        totalServed++;
        totalWaitTime += waitTime;
        if (waitTime > maxWaitTime) maxWaitTime = waitTime;
        totalServiceTime += serviceTime;
    }

    public void updateQueueLength(int len) {
        if (len > maxQueueLength) maxQueueLength = len;
    }

    public void deliveryOccurred(double fuelBefore) {
        deliveriesCount++;
        totalFuelBeforeDeliveries += fuelBefore;
    }

    public void updateMinFuelReserve(double fuel) {
        if (fuel < minFuelReserve) minFuelReserve = fuel;
    }

    public void pumpServiceRecord(int pumpId, double duration) {
        pumpServiceTime.merge(pumpId, duration, Double::sum);
    }

    public void pumpOpenRecord(int pumpId, double openTime) {
        pumpOpenTime.put(pumpId, openTime);
    }

    public void printReport(double simEndTime) {
        double avgFuel = deliveriesCount > 0 ? totalFuelBeforeDeliveries / deliveriesCount : 0;
        double avgWait = totalServed > 0 ? totalWaitTime / totalServed : 0;
        double avgService = totalServed > 0 ? totalServiceTime / totalServed : 0;

        System.out.println("------ Results of Simulation ------");
        System.out.printf("Car arrived: %d\n", totalArrived);
        System.out.printf("Served: %d\n", totalServed);
        System.out.printf("Rejects, cuz no fuel: %d\n", totalRefused);
        System.out.printf("Average expectation in queue: %.2f мин\n", avgWait);
        System.out.printf("Maximum expectation time: %.2f мин\n", maxWaitTime);
        System.out.printf("Maximum length of queue: %d\n", maxQueueLength);
        System.out.printf("Pumps at the end: %d\n", pumpOpenTime.size());
        System.out.printf("Amount of opened pumps: %d\n", expansionsCount);
        System.out.printf("Amount of deliveries: %d\n", deliveriesCount);
        System.out.printf("Average Fuel: %.2f л\n", avgFuel);
        System.out.printf("Min Fuel: %.2f л\n", minFuelReserve == Double.MAX_VALUE ? 0 : minFuelReserve);
        System.out.print("Load of pumps: ");

        for (int id : pumpOpenTime.keySet()) {
            double totalTime = simEndTime - pumpOpenTime.get(id);
            double busyTime = pumpServiceTime.getOrDefault(id, 0.0);
            double util = totalTime > 0 ? (busyTime / totalTime) * 100 : 0;
            System.out.printf("#%d: %.1f%% ", id, util);
        }

        System.out.println();
    }
}