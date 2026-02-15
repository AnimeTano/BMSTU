public class Event implements Comparable<Event> {
    private String type;
    private Object data;
    private double time;

    public Event(String type, Object data, double time) {
        this.type = type;
        this.data = data;
        this.time = time;
    }

    public Event(String type, double time) {
        this(type, null, time);
    }

    public String getType() { return type; }
    public Object getData() { return data; }
    public double getTime() { return time; }

    @Override
    public int compareTo(Event other) {
        return Double.compare(this.time, other.time);
    }
}