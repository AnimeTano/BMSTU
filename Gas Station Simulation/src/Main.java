import java.util.*;

public class Main {
    public static void main(String[] args) {
        Config config = new Config();
        Statistics stats = new Statistics();
        Random random = new Random(config.getRandomSeed());
        CarGenerator carGenerator = new CarGenerator(random, config);
        GasStation station = new GasStation(config, stats);
        Simulation sim = new Simulation(config, station, carGenerator, stats);
        sim.run();
    }
}