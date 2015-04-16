/**
 * Created by ikaros on 2015/3/24.
 */
public class Teacher extends Member {
    Boolean fulltime;

    public Teacher() {
        super();
    }

    public Teacher(int ID, String dept, Boolean fulltime) {
        super(ID, dept);
        this.fulltime = fulltime;
    }

    public Boolean getFulltime() {
        return fulltime;
    }

    public void setFulltime(Boolean fulltime) {
        this.fulltime = fulltime;
    }

    @Override
    public String toString() {
        return String.format("%d, %s, %b", this.id, this.dept, this.getFulltime());
    }
}
