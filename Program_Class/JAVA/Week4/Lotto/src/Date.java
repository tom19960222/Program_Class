/**
 * Created by ikaros on 2015/3/16.
 */
public class Date {
    int year, month, day;

    public Date(int year, int month, int day) {
        this.year = year;
        this.month = month;
        this.day = day;
    }

    @Override
    public String toString() {
        return String.format("%d/%d/%d", year, month, day);
    }
}
