/**
 * Created by ikaros on 2015/3/2.
 */
public class VertTriangle extends Triangle {
    public enum Direction {LEFTUP, LEFTDOWN, RIGHTUP, RIGHTDOWN}
    private Direction TriangleDirection;
    public VertTriangle()
    {
        this(0, false, Direction.LEFTUP);
    }
    public VertTriangle(int height)
    {
        this(height, false, Direction.LEFTUP);
    }
    public VertTriangle(int height, Boolean filled)
    {
        this(height, filled, Direction.LEFTUP);
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
            case LEFTUP: return "LeftUp";
            case LEFTDOWN: return "LeftDown";
            case RIGHTUP: return "RightUp";
            case RIGHTDOWN: return "RightDown";
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
            case LEFTUP:
                for (int i = 1; i <= height; i++) {
                    for (int j = 1; j <= height; j++) {
                        if (i == 1 || j == 1 || i + j == height + 1 || (filled && (i + j) <= height + 1))
                            System.out.print('*');
                        else System.out.print(' ');
                    }
                    System.out.println();
                }
                break;
            case LEFTDOWN:
                for (int i = 1; i <= height; i++)
                {
                    for (int j = 1; j <= height; j++) {
                        if (i == height || j == 1 || j == 1 || i == j || (filled && i >= j)) System.out.print('*');
                        else System.out.print(' ');
                    }
                    System.out.println();
                }
                break;
            case RIGHTUP:
                for (int i = 1; i <= height; i++)
                {
                    for (int j = 1; j <= height; j++) {
                        if (i == 1 || j == height || i == j || (filled && j >= i)) System.out.print('*');
                        else System.out.print(' ');
                    }
                }
                System.out.println();
                break;
            case RIGHTDOWN:
                for (int i = 1; i <= height; i++)
                {
                    for (int j = 1; j <= height; j++) {
                        if (i == height || j == 1 || j == 1 || i == j || (filled && i >= j)) System.out.print('*');
                        else System.out.print(' ');
                    }
                }
                System.out.println();
                break;
        }
    }
}
