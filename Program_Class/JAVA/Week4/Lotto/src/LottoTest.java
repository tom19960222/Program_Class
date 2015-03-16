/**
 * Created by ikaros on 2015/3/16.
 */
public class LottoTest {
    public static void main(String[] args)
    {
        int MAX = 30;
        Lotto[] lotto = new Lotto[MAX];
        Date[] date = new Date[MAX];

        date[0] = new Date(2012,1,1);
        date[1] = new Date(2012,1,8);
        date[2] = new Date(2012,1,15);
        date[3] = new Date(2012,1,22);
        date[4] = new Date(2012,1,29);


        for (int i = 0; i < 5; i++) {
            lotto[i] = new Lotto();
            lotto[i].setDate(date[i]);
            //lotto[i].draw();
        }

        System.out.println(lotto[0]);
        for(int i=0;i<5;i++)
            System.out.println(String.format("[0%d] %s", i+1, lotto[i].toString()));

    }
}
