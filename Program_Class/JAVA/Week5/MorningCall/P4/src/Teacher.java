/**
 * Created by ikaros on 2015/3/24.
 */
public class Teacher extends Member {
    @Override
    public String toString() {
        return String.format("%d, %s, %b", this.id, this.dept, this.getFulltime());
    }

    public Boolean getFulltime() {
        return fulltime;
    }

    public void setFulltime(Boolean fulltime) {
        this.fulltime = fulltime;
    }

    Boolean fulltime;
    public Teacher(int ID, String dept, Boolean fulltime) {
        this.id = ID;
        this.dept = dept;
        this.fulltime = fulltime;
    }

    public Teacher() {
    }
}
