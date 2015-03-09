package net.hsexpert.OOPShape;

/**
 * Created by ikaros on 2015/3/3.
 */
public abstract class ShapeBase implements IShape{
    public void prchar(char ch, int times)
    {
        for (int i = 0; i < times; i++)
            System.out.print(ch);
    }
}