import java.util.ArrayList;
import java.util.List;
import java.util.Random;

/**
 * Created by ikaros on 2015/3/16.
 */
public class Lotto {
    private Date date;
    private List<Integer> Nums;

    public Lotto() {
        int rndNum;
        Random rnd = new Random();
        Nums = new ArrayList<Integer>();
        for (int i = 0; i < 6; i++) {
            rndNum = rnd.nextInt(49) + 1;
            if (Nums.contains(rndNum)){ i--; continue; }
            Nums.add(rndNum);
        }
    }

    public void setDate(Date date) {
        this.date = date;
    }
    public void draw()
    {
        System.out.println(this.toString());
    }

    @Override
    public String toString() {
        StringBuffer SB = new StringBuffer();
        SB.append(date.toString());
        for(int i = 0; i < 6; i++)
            SB.append(String.format(" %d", Nums.get(i)));
        return SB.toString();
    }
}
