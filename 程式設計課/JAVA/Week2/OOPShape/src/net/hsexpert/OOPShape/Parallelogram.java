package net.hsexpert.OOPShape;

/**
 * Created by ikaros on 2015/3/3.
 */
public class Parallelogram extends Rect {
    public enum Direction {Left, Right};
    private Direction _direction = Direction.Left;
    public Parallelogram(){super();}
    public Parallelogram(int width, int height){super(width, height);}
    public Parallelogram(int width, int height, Boolean filled){super(width, height, filled);}
    public Parallelogram(int width, int height, Boolean filled, Direction Dir){super(width, height, filled); _direction = Dir;}

    public Direction getDirection() {
        return _direction;
    }
    public String getDirectionString() {
        switch(_direction)
        {
            case Left: return "Left";
            case Right: return "Right";
        }
        return "";
    }

    public void draw()
    {
        if (_direction == Direction.Right) {
            for (int i = 0; i < height; i++) {
                prchar(' ', height - i - 1);
                for (int j = 0; j < width; j++) {
                    if (j == 0 || j == width - 1 || i == 0 || i == height - 1 || filled) System.out.print("*");
                    else System.out.print(" ");
                }
                System.out.println();
            }
        }
        else {
            for (int i = height-1; i >= 0; i--) {
                prchar(' ', height - i - 1);
                for (int j = 0; j < width; j++) {
                    if (j == 0 || j == width - 1 || i == 0 || i == height - 1 || filled) System.out.print("*");
                    else System.out.print(" ");
                }
                System.out.println();
            }
        }
    }
    public String toString()
    {
        return String.format("Parallelogram:\n  Width: %d\n  Height: %d\n  Filled: %s\n  Direction: %s", width, height, filled.toString(), getDirectionString());
    }
}
