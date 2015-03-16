package net.hsexpert.OOPShape;

/**
 * Created by ikaros on 2015/3/2.
 */

import java.util.*;

public class Main {
    public static void main(String[] args)
    {
        int width, height;
        Boolean filled;
        Scanner S = new Scanner(System.in);
        Random Rand = new Random();
    /*    System.out.print("Input width: ");
                width = S.nextInt();
                System.out.print("Input height: ");
                height = S.nextInt();
                System.out.print("Wanna the graph inside filled? (true/false) ");
                filled = S.nextBoolean();
        */
        width = Rand.nextInt(9)+3;
        height = Rand.nextInt(9)+3;
        filled = Rand.nextBoolean();
        List<Shape> ShapeList = new ArrayList<Shape>();
        Rect R1 = new Rect(width, height, filled);
        System.out.println(R1);
        R1.draw();
        System.out.println();
        Square S1 = new Square(width);
        System.out.println(S1);
        S1.draw();
        System.out.println();
        VertTriangle V1 = new VertTriangle(height, filled, VertTriangle.Direction.LeftDown);
        System.out.println(V1);
        V1.draw();
        System.out.println();
        VertTriangle V2 = new VertTriangle(height, filled, VertTriangle.Direction.RightUp);
        System.out.println(V2);
        V2.draw();
        System.out.println();
        Parallelogram P1 = new Parallelogram(width,height,filled, Parallelogram.Direction.Right);
        System.out.println(P1);
        P1.draw();
        System.out.println();
        Parallelogram P2 = new Parallelogram(width,height,filled, Parallelogram.Direction.Left);
        System.out.println(P2);
        P2.draw();
        System.out.println();
        IsoscelesTriangle I1 = new IsoscelesTriangle(height, filled, IsoscelesTriangle.Direction.Up);
        System.out.println(I1);
        I1.draw();
        System.out.println();
        IsoscelesTriangle I2 = new IsoscelesTriangle(height, filled, IsoscelesTriangle.Direction.Down);
        System.out.println(I2);
        I2.draw();
        ShapeList.add(R1);
        ShapeList.add(S1);
        ShapeList.add(V1);
        ShapeList.add(V2);
        ShapeList.add(P1);
        ShapeList.add(P2);
        ShapeList.add(I1);
        ShapeList.add(I2);
        for (Shape Sha : ShapeList)
            Sha.draw();
        S.close();
    }
}
