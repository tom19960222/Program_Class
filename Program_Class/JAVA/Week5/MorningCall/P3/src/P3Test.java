/**
 * Created by ikaros on 2015/3/24.
 */
public class P3Test {
    public static void main(String[] args)
    {
        Student stud1 = new Student(100,"CSIE","1B",0);
        Student stud2 = new Student(110,"CSIE","1C",1);
        Student stud3 = new Student();
        stud3.setID(120);
        stud3.setDept("EE");
        stud3.setInClass("1A");
        stud3.setFail21(1);

        Teacher teacher1 = new Teacher(10000,"CSIE",true);
        Teacher teacher2 = new Teacher();
        teacher2.setID(10001);
        teacher2.setDept("Math");
        teacher2.setFulltime(false);

        System.out.println("Student 1: " + stud1);
        System.out.println("Student 2: " + stud2);
        System.out.println("Student 3: " + stud3);
        System.out.println("Teacher 1: " + teacher1);
        System.out.println("Teacher 2: " + teacher2);
    }
}
