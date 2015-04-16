/**
 * Created by ikaros on 2015/3/24.
 */
public class Member {
    protected int id;
    protected String dept;

    public Member() {
    }

    public Member(int id, String dept) {
        this.id = id;
        this.dept = dept;
    }

    public int getID() {
        return id;
    }

    public void setID(int id) {
        this.id = id;
    }

    public String getDept() {
        return dept;
    }

    public void setDept(String dept) {
        this.dept = dept;
    }
}
