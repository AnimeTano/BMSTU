import java.util.*;

public class CarGenerator {
    private Random random;
    private Config config;

    public CarGenerator(Random random, Config config) {
        this.random = random;
        this.config = config;
    }

    private double getLambda(double timeMinutes) {
        double hour = (timeMinutes / 60.0) % 24;
        if (hour < 6) return 0.03;
        else if (hour < 10) return 0.25;
        else if (hour < 16) return 0.12;
        else if (hour < 20) return 0.30;
        else return 0.08;
    }

    public double generateNextInterval(double currentTime) {
        double lambda = getLambda(currentTime);
        double u = random.nextDouble();
        if (u == 0.0) u = 1e-10;
        return -Math.log(u) / lambda;
    }

    public Car generateCar(double arrivalTime) {
        double tankCapacity = 40 + 10 * random.nextInt(5);
        double fuelLevel = tankCapacity * (0.1 + 0.8 * random.nextDouble());
        double freeSpace = tankCapacity - fuelLevel;
        double desired;
        if (freeSpace < 5) {
            desired = freeSpace;
        } else {
            desired = 5 + random.nextDouble() * (freeSpace - 5);
        }
        return new Car(tankCapacity, fuelLevel, desired, arrivalTime);
    }
}