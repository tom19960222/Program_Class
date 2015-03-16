/**
 * Created by ikaros on 2015/3/11.
 */
public class SalariedEmployee extends Employee{
    private int Salary;

    public SalariedEmployee() {
        super();
        this.Salary = 0;
    }

    public SalariedEmployee(int Salary)  {
        this();
        this.Salary = Salary;
    }

    public SalariedEmployee(String Name, String ID, int EmpID, String Title, int Salary) {
        this.Name = Name;
        this.ID = ID;
        this.EmpID = EmpID;
        this.Title = Title;
        this.Salary = Salary;
    }

    public int getSalary() {
        return Salary;
    }

    public void setSalary(int salary) {
        Salary = salary;
    }

    public int year_earning(){
        return Salary * 12;
    }

    @Override
    public String toString() {
        return String.format("SalariedEmployee with salary %d per month", Salary);
    }
}
