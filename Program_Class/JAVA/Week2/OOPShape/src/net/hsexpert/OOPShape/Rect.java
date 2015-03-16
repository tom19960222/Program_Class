package net.hsexpert.OOPShape;

/**
 * Created by ikaros on 2015/3/2.
 */
public class Rect extends Shape {
    protected int width;
    protected int height;
    protected Boolean filled;

    public Rect()
    {
        this(0,0,false);
    }

    public Rect(int width, int height)
    {
        this(width, height, false);
    }

    public Rect (int width, int height, Boolean filled)
    {
        this.width = width;
        this.height = height;
        this.filled = filled;
    }

    public int getWidth() {return width;}
    public int getHeight() {return height;}
    public Boolean isFilled() {return filled;}

    public void setWidth(int value) {width = value;}
    public void setHeight(int value) {height = value;}
    public void setFilled(Boolean value) {filled = value;}

    public void draw()
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++) {
                if (j == 0 || j == width - 1 || i == 0 || i == height - 1 || filled) System.out.print("*");
                else System.out.print(" ");
            }
            System.out.println();
        }
    }

    public String toString()
    {
        return String.format("Rect:\n  Width: %d\n  Height:%d\n  Filled: %s", width, height, filled.toString());
    }
}
