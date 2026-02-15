import java.util.*;


public class Config {
    private double simulationDays = 12;
    private int initialPumps = 1;
    private int maxPumps = 10;
    private double defaultFlowRate = 2.5;
    private double queueThreshold = 12.0;
    private double expansionDelay = 2.0;
    private double initialFuel = 10000.0;
    private double maxFuelCapacity = 15000.0;
    private double deliveryInterval = 24.0;
    private double deliveryVolume = 10000.0;
    private double deliveryDuration = 30.0;
    private long randomSeed = 42;

    public double getSimulationDays() { return simulationDays; }
    public int getInitialPumps() { return initialPumps; }
    public int getMaxPumps() { return maxPumps; }
    public double getDefaultFlowRate() { return defaultFlowRate; }
    public double getQueueThreshold() { return queueThreshold; }
    public double getExpansionDelay() { return expansionDelay; }
    public double getInitialFuel() { return initialFuel; }
    public double getMaxFuelCapacity() { return maxFuelCapacity; }
    public double getDeliveryInterval() { return deliveryInterval; }
    public double getDeliveryVolume() { return deliveryVolume; }
    public double getDeliveryDuration() { return deliveryDuration; }
    public long getRandomSeed() { return randomSeed; }
}
