/**
 * Created by ikaros on 2015/3/11.
 */
public class Main {
    public static void main(String[] args) {
        Employee emp[] = new Employee[10];
        int Num=0;

        emp[0] = new SalariedEmployee("John","A123456789",1100, "Manager",60000);
        Num++;
        emp[1] = new HourlyEmployee("Joyce","J376829345",1200, "Secretary",2500, 130);
        Num++;
        emp[2] = new SalariedEmployee(50000);  // Salary=50000
        emp[2].setName("David");
        emp[2].setID("B135798642");
        emp[2].setEmpID(1151);
        emp[2].setTitle("Engineer");
        Num++;

        for(int i=0;i<Num;i++){
            System.out.println("--------------------------------------");
            System.out.println("Name: "+emp[i].getName());
            System.out.println("ID: "+emp[i].getID());
            System.out.println("EmpID: " + emp[i].getEmpID());
            System.out.println("Title: "+emp[i].getTitle());
            System.out.println(emp[i]);
            System.out.println("Year earning: "+emp[i].year_earning());
        }
        System.out.println("--------------------------------------");
    }
}
