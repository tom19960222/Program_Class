package net.hsexpert;

import java.awt.*;
import java.util.Random;

/**
 * Created by ikaros on 2015/4/7.
 */
public class Triangle extends Shape {
    int x3, y3;
    public Triangle(int x1, int y1, int x2, int y2, int x3, int y3) {
        super(x1,y1,x2,y2);
        this.x3 = x3;
        this.y3 = y3;
    }
    @Override
    public void draw(Graphics G) {
        if(!this.visible) return;
        Graphics2D g2d = (Graphics2D)G;
        g2d.setColor(this.color);
        if(this.filled)
            g2d.fillPolygon(new int[]{x1, x2, x3}, new int[]{y1, y2, y3}, 3);
        else
            g2d.drawPolygon(new int[]{x1, x2, x3}, new int[]{y1, y2, y3}, 3);
    }

    public static Triangle generateRandomTriangle()
    {
        Random rnd = new Random();
        int x1, x2, y1, y2, x3, y3, R, G, B;
        x1 = rnd.nextInt(1280);
        x2 = rnd.nextInt(1280);
        x3 = rnd.nextInt(1280);
        y1 = rnd.nextInt(720);
        y2 = rnd.nextInt(720);
        y3 = rnd.nextInt(720);
        R = rnd.nextInt(255);
        G = rnd.nextInt(255);
        B = rnd.nextInt(255);

        Triangle Tri = new Triangle(x1, y1, x2, y2, x3, y3);
        Tri.setColor(new Color(R, G, B));
        Tri.setFilled(rnd.nextBoolean());

        return Tri;
    }
}
