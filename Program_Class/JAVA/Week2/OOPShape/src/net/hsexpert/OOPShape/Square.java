package net.hsexpert.OOPShape;

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
    public String toString()
    {
        return String.format("Square:\n  Lenth: %d\n  Filled: %s", width, filled.toString());
    }
}
