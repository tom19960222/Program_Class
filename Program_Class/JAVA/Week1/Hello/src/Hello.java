/**
 * Created by ikaros on 2015/2/25.
 */

import java.io.*;
import java.util.Scanner;
public class Hello {
    public static void main (String[] args) throws IOException{
        int abc;

        Scanner play = new Scanner(System.in);
        abc = play.nextInt();
        System.out.println("HELLO"+abc);
    }
}
