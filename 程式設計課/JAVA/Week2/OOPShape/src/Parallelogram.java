/**
 * Created by ikaros on 2015/3/3.
 */
public class Parallelogram extends Rect {
    public Parallelogram(){super();}
    public Parallelogram(int width, int height){super(width, height);}
    public Parallelogram(int width, int height, Boolean filled){super(width, height, filled);}

    public void draw()
    {
            for (int i = 0; i < height; i++)
            {
                prchar(' ', height-i-1);
                for (int j = 0; j < width; j++) {
                    if (j == 0 || j == width - 1 || i == 0 || i == height - 1 || filled) System.out.print("*");
                    else System.out.print(" ");
                }
                System.out.println();
            }
    }
}
