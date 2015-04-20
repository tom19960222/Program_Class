package net.hsexpert.painter;

import java.awt.*;
import java.util.Random;

/**
 * Created by ikaros on 2015/4/7.
 */
public class Triangle extends net.hsexpert.painter.Shape {
    int x3, y3;
    public Triangle(int x1, int y1, int x2, int y2, int x3, int y3) {
        super(x1,y1,x2,y2);
        this.x3 = x3;
        this.y3 = y3;
        this.setColor1(Color.BLACK);
        this.setColor2(Color.BLACK);
        this.setFilled(false);
        this.setStrokeWidth(10);
        this.setGradient(false);
    }
    public Triangle(int x1, int y1, int x2, int y2)
    {
        super();
        this.setPointer(x1, y1, x2, y2);
        this.setColor1(Color.BLACK);
        this.setColor2(Color.BLACK);
        this.setFilled(false);
        this.setStrokeWidth(10);
        this.setGradient(false);
    }
    public Triangle(int x1, int y1, int x2, int y2, int x3, int y3, Color color1, Color color2, Boolean filled, int strokeWidth, Boolean gradient) {
        this(x1, y1, x2, y2, x3, y3);
        this.setColor1(color1);
        this.setColor2(color2);
        this.setFilled(filled);
        this.setStrokeWidth(strokeWidth);
        this.setGradient(gradient);
    }
    public Triangle(int x1, int y1, int x2, int y2, Color color1, Color color2, Boolean filled, int strokeWidth, Boolean gradient) {
        this(x1, y1, x2, y2);
        this.setColor1(color1);
        this.setColor2(color2);
        this.setFilled(filled);
        this.setStrokeWidth(strokeWidth);
        this.setGradient(gradient);
    }
    public Triangle(Triangle src)
    {
        this.x1 = src.x1;
        this.y1 = src.y1;
        this.x2 = src.x2;
        this.y2 = src.y2;
        this.x3 = src.x3;
        this.y3 = src.y3;
        this.setColor1(src.color1);
        this.setColor2(src.color2);
        this.setFilled(src.filled);
        this.strokeWidth = src.strokeWidth;
        this.gradient = src.gradient;
    }
    public void setPointer(int x1, int y1, int x2, int y2)
    {
        this.x1 = x1;
        this.y1 = y2;
        this.x2 = (x1+x2)/2;
        this.y2 = y1;
        this.x3 = x2;
        this.y3 = y2;
    }
    public void setPointerWithThreePoints(int x1, int y1, int x2, int y2, int x3, int y3)
    {
        this.x1 = x1;
        this.y1 = y2;
        this.x2 = x2;
        this.y2 = y2;
        this.x3 = x3;
        this.y3 = y3;
    }

    @Override
    public void draw(Graphics G) {
        if(!this.visible) return;
        Graphics2D g2d = (Graphics2D)G;
        g2d.setStroke(new BasicStroke(strokeWidth));
        if (gradient) g2d.setPaint(new GradientPaint(10,10,color1,20,20,color2,true));
        else g2d.setColor(this.color1);
        if(this.filled)
            g2d.fillPolygon(new int[]{x1, x2, x3}, new int[]{y1, y2, y3}, 3);
        else
            g2d.drawPolygon(new int[]{x1, x2, x3}, new int[]{y1, y2, y3}, 3);
    }

    public static Triangle generateRandomTriangle()
    {
        Random rnd = new Random();
        int x1, x2, y1, y2, x3, y3, R1, G1, B1, R2, G2, B2;
        x1 = rnd.nextInt(1280);
        x2 = rnd.nextInt(1280);
        x3 = rnd.nextInt(1280);
        y1 = rnd.nextInt(720);
        y2 = rnd.nextInt(720);
        y3 = rnd.nextInt(720);
        R1 = rnd.nextInt(255);
        G1 = rnd.nextInt(255);
        B1 = rnd.nextInt(255);
        R2 = rnd.nextInt(255);
        G2 = rnd.nextInt(255);
        B2 = rnd.nextInt(255);

        Triangle Tri = new Triangle(x1, y1, x2, y2, x3, y3);
        Tri.setColor1(new Color(R1, G1, B1));
        Tri.setColor2(new Color(R2, G2, B2));
        Tri.setFilled(rnd.nextBoolean());
        Tri.setGradient(rnd.nextBoolean());

        return Tri;
    }
}
