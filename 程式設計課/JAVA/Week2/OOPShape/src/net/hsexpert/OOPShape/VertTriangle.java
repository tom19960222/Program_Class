package net.hsexpert.OOPShape;

/**
 * Created by ikaros on 2015/3/2.
 */
public class VertTriangle extends Triangle {
    public enum Direction {Leftup, LeftDown, RightUp, RightDown}
    private Direction TriangleDirection;
    public VertTriangle()
    {
        this(0, false, Direction.Leftup);
    }
    public VertTriangle(int height)
    {
        this(height, false, Direction.Leftup);
    }
    public VertTriangle(int height, Boolean filled)
    {
        this(height, filled, Direction.Leftup);
    }
    public VertTriangle(int height, Boolean filled, Direction Dirct)
    {
        super(height, filled);
        TriangleDirection = Dirct;
    }

    public String getDirection()
    {
        switch(TriangleDirection)
        {
            case Leftup: return "LeftUp";
            case LeftDown: return "LeftDown";
            case RightUp: return "RightUp";
            case RightDown: return "RightDown";
        }
        return "";
    }

    public void setDirection(Direction Direct)
    {
        TriangleDirection = Direct;
    }

    public void draw()
    {
        switch(TriangleDirection)
        {
            case Leftup:
                for (int i = 1; i <= height; i++) {
                    for (int j = 1; j <= height; j++) {
                        if (i == 1 || j == 1 || i + j == height + 1 || (filled && (i + j) <= height + 1))
                            System.out.print('*');
                        else System.out.print(' ');
                    }
                    System.out.println();
                }
                break;
            case LeftDown:
                for (int i = 1; i <= height; i++)
                {
                    for (int j = 1; j <= height; j++) {
                        if (i == height || j == 1 || j == 1 || i == j || (filled && i >= j)) System.out.print('*');
                        else System.out.print(' ');
                    }
                    System.out.println();
                }
                break;
            case RightUp:
                for (int i = 1; i <= height; i++) {
                    for (int j = 1; j <= height; j++)
                        System.out.printf ("%c", (i == 1 || j == height || i == j || (filled && j >= i)) ? '*' : ' ');
                    System.out.println();
                }
                break;
            case RightDown:
                for (int i = 1; i <= height; i++)
                {
                    for (int j = 1; j <= height; j++) {
                        if (i == height || j == 1 || j == 1 || i == j || (filled && i >= j)) System.out.print('*');
                        else System.out.print(' ');
                    }
                    System.out.println();
                }

                break;
        }
    }
}
