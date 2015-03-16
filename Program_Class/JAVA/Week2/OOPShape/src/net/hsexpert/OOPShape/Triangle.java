package net.hsexpert.OOPShape;

/**
 * Created by ikaros on 2015/3/2.
 */
public abstract class Triangle extends Shape {

    protected int height;
    protected Boolean filled;

    public Triangle()
    {
        this(0, false);
    }

    public Triangle(int height)
    {
        this(height, false);
    }

    public Triangle(int height, Boolean filled)
    {
        this.height = height;
        this.filled = filled;
    }

    public int getHeight() {return height;}
    public Boolean getFilled() {return filled;}

    public void setHeight(int value) {height = value;}
    public void setFilled(Boolean value) {filled = value;}
    public void draw()
    {

    }
}
