public class FuelPump {
    private int id;
    private static int firstId = 1;
    private double flowRate;
    private boolean busy;
    private Car currentCar;
    private double openTime;
    private double totalServiceTime;

    public FuelPump(double flowRate, double openTime) {
        this.id = firstId++;
        this.flowRate = flowRate;
        this.openTime = openTime;
        this.busy = false;
        this.currentCar = null;
        this.totalServiceTime = 0.0;
    }

    public int getId() { return id; }
    public double getFlowRate() { return flowRate; }
    public boolean isBusy() { return busy; }
    public Car getCurrentCar() { return currentCar; }
    public double getOpenTime() { return openTime; }
    public double getTotalServiceTime() { return totalServiceTime; }

    public void serviceMaintenance(Car car, double currentTime) {
        this.currentCar = car;
        this.busy = true;

        car.setStartServiceTime(currentTime);
        double serviceDuration = car.getDesiredFuel() / flowRate;
        car.setEndServiceTime(currentTime + serviceDuration);
    }

    public void freePump() {
        this.busy = false;
        this.currentCar = null;
    }

    public void addServiceTime(double duration) {
        totalServiceTime += duration;
    }
}