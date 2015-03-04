/**
 * Created by ikaros on 2015/3/2.
 */
public class Square extends Rect {
    public Square()
    {
        super();
    }

    public Square(int lenth)
    {
        super(lenth,lenth, false);
    }

    public Square(int lenth, Boolean filled) { super(lenth, lenth, filled); }
}
