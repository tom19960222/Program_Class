package net.hsexpert.OOPShape;

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
        VertTriangle V1 = new VertTriangle(10, false, VertTriangle.Direction.LeftDown);
        V1.draw();
        System.out.println();
        VertTriangle V2 = new VertTriangle(5, true, VertTriangle.Direction.RightUp);
        V2.draw();
        System.out.println();
        Parallelogram P1 = new Parallelogram(10,5,true, Parallelogram.Direction.Right);
        P1.draw();
        System.out.println();
        Parallelogram P2 = new Parallelogram(5,8,false, Parallelogram.Direction.Left);
        P2.draw();
        System.out.println();
        IsoscelesTriangle I1 = new IsoscelesTriangle(6, true, IsoscelesTriangle.Direction.Up);
        I1.draw();
        System.out.println();
        IsoscelesTriangle I2 = new IsoscelesTriangle(4, false, IsoscelesTriangle.Direction.Down);
        I2.draw();
    }
}
