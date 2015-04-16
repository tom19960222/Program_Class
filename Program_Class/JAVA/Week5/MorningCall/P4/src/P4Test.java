/**
 * Created by ikaros on 2015/3/25.
 */
public class P4Test {
    public static void main(String[] args)
    {
        int MAX = 30;
        int numMembers = 0;
        Member member[] = new Member[MAX];
        member[numMembers++] = new Student(100,"CSIE","1B",0);
        member[numMembers++] = new Student(110,"CSIE","1C",1);
        Student tempStu = new Student();
        tempStu.setId(120);
        tempStu.setDept("EE");
        tempStu.setInClass("1A");
        tempStu.setFail21(1);
        member[numMembers++] = tempStu;

        // add teachers data here
        Teacher tempTeach = new Teacher();
        tempTeach.setFulltime(true);
        tempTeach.setDept("CS");
        tempTeach.setId(999);
        member[numMembers++] = tempTeach;

        // use a loop to display all data
        for(int i = 0; i < numMembers; i++)
            System.out.println(member[i]);
    }
}
