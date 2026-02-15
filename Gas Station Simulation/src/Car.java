public class Car {
    private int id;
    private static int firstId = 1;

    private double tankCapacity;
    private double fuelLevel;
    private double desiredFuel;
    private double arrivalTime;
    private double startServiceTime;
    private double endServiceTime;

    public Car(double tankCapacity, double fuelLevel, double desiredFuel, double arrivalTime) {
        this.id = firstId++;
        this.tankCapacity = tankCapacity;
        this.fuelLevel = fuelLevel;
        this.arrivalTime = arrivalTime;

        double freeSpace = tankCapacity - fuelLevel;
        if (desiredFuel < 0) desiredFuel = 0;

        if (desiredFuel > freeSpace) {
            this.desiredFuel = freeSpace;
        } else this.desiredFuel = desiredFuel;
    }

    public int getId() { return id; }
    public double getTankCapacity() { return tankCapacity; }
    public double getFuelLevel() { return fuelLevel; }
    public double getDesiredFuel() { return desiredFuel; }
    public double getArrivalTime() { return arrivalTime; }
    public double getStartServiceTime() { return startServiceTime; }
    public double getEndServiceTime() { return endServiceTime; }

    public void setStartServiceTime(double startServiceTime) {
        this.startServiceTime = startServiceTime;
    }

    public void setEndServiceTime(double endServiceTime) {
        this.endServiceTime = endServiceTime;
    }
}
