import java.util.Scanner;

public class P2Test {
    public static void main(String[] args) {
        int height;
        int shape;
        final int Triangle = 1;
        final int Square = 2;
        Scanner input = new Scanner(System.in);
             // initialize height = 5, shape = 1 (Triangle)
        P2 s1 = new P2(5,Triangle);
        System.out.printf("shape: %s; height: %d\n", s1.getShape(), s1.getHeight());
        s1.draw();
        System.out.println();
        P2 s2 = new P2();
        System.out.print("Enter height: ");
        height = input.nextInt();
        System.out.print("Enter shape (1 for Triangle, 2 for Square): ");
        shape = input.nextInt();
        s2.setHeight(height);
        s2.setShape(shape);
        System.out.printf("shape: %s; height: %d\n", s2.getShape(), s2.getHeight());
        s2.draw();
        System.out.println();        // initialize height = 7
        P2 s3 = new P2(7);
        System.out.println("Draw all shapes");
        s3.drawAll();
    }
}