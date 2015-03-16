/**
 * Created by ikaros on 2015/3/11.
 */
public abstract class Employee {
    protected String Name, ID, Title;
    protected int EmpID;

    public Employee(){
        this.Name = "";
        this.ID = "";
        this.Title = "";
        this.EmpID = 0;
    }

    public Employee(String name, String ID, String title, int empID) {
        Name = name;
        this.ID = ID;
        Title = title;
        EmpID = empID;
    }

    public String getID() {
        return ID;
    }

    public void setID(String ID) {
        this.ID = ID;
    }

    public String getTitle() {
        return Title;
    }

    public void setTitle(String title) {
        Title = title;
    }

    public int getEmpID() {
        return EmpID;
    }

    public void setEmpID(int empID) {
        EmpID = empID;
    }

    public String getName() {

        return Name;
    }
    public void setName(String name) {
        Name = name;
    }

    public abstract int year_earning();
}
