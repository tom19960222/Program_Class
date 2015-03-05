/**
 * Created by ikaros on 2015/3/2.
 */

public class Main {
    public static void main(String[] args)
    {
        Rect R1 = new Rect(10,5);
        R1.draw();
        System.out.println();
        Square S1 = new Square(10);
        S1.draw();
        System.out.println();
        VertTriangle V1 = new VertTriangle(10, false, VertTriangle.Direction.LEFTDOWN);
        V1.draw();
        System.out.println();
        Parallelogram P1 = new Parallelogram(10,5);
        P1.draw();
        System.out.println();
    }
}
