/**
 * Created by ikaros on 2015/3/24.
 */
public class Student extends Member {
    private String inClass;
    private int fail21;

    public Student() {
        super();
    }

    public Student(int ID, String dept, String inClass, int fail21) {
        super(ID, dept);
        this.inClass = inClass;
        this.fail21 = fail21;
    }

    public int getFail21() {
        return fail21;
    }

    public void setFail21(int fail21) {
        this.fail21 = fail21;
    }

    public String getInClass() {
        return inClass;
    }

    public void setInClass(String inClass) {
        this.inClass = inClass;
    }

    @Override
    public String toString() {
        return String.format("%d, %s, %s, %d", this.id, this.dept, this.getInClass(), this.fail21);
    }
}
