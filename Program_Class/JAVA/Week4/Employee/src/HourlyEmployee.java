/**
 * Created by ikaros on 2015/3/11.
 */
public class HourlyEmployee extends Employee{
    private int WorkingHours, MoneyPerHour;
    public HourlyEmployee()
    {
        this.MoneyPerHour = 0;
        this.WorkingHours = 0;
    }
    public HourlyEmployee(String Name, String ID, int EmpID, String Title, int WorkingHours, int MoneyPerHour)
    {
        super(Name, ID, Title, EmpID);
        this.MoneyPerHour = MoneyPerHour;
        this.WorkingHours = WorkingHours;
    }
    public int year_earning() {return WorkingHours*MoneyPerHour;}

    public String toString() { return String.format("Hourly Employee with the rate of %d dollars per hour", MoneyPerHour);}
}
