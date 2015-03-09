package net.hsexpert.OOPShape;

/**
 * Created by ikaros on 2015/3/9.
 */
public class IsoscelesTriangle extends Triangle {
    public enum Direction {Up, Down};
    public IsoscelesTriangle() {super();}
    public IsoscelesTriangle(int height) {super(height);}
    public IsoscelesTriangle(int height, Boolean filled) {super(height, filled);}
    public IsoscelesTriangle(int height, Boolean filled, Direction Dir) {super(height, filled); _direction = Dir;}
    private Direction _direction = Direction.Up;

    public Direction getDirection() {
        return _direction;
    }

    public void draw()
    {
        if (_direction == Direction.Up){
            for (int i = 1; i <= height; i++)
            {
                for (int j = 1 ; j < height*2; j++)
                    System.out.printf ("%c", ((j == height && i == 1) ||  j == height-i+1 || j == height+i-1 || i == height || (filled && (j > height-i+1 && j < height+i-1))) ? '*' : ' ');
                System.out.println();
            }
        }
        else {
            for (int i = height; i >= 1; i--)
            {
                for (int j = 1 ; j < height*2; j++)
                    System.out.printf("%c", ((i == 1 && j == height) || j == height - i + 1 || j == height + i - 1 || i == height || (filled && (j >= height - i + 1 && j <= height + i - 1))) ? '*' : ' ');
                System.out.println();
            }
        }
    }
}

