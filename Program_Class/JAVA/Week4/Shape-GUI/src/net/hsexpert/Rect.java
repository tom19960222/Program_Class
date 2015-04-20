package net.hsexpert;

import java.awt.*;
import java.util.Random;

/**
 * Created by ikaros on 2015/3/17.
 */
public class Rect extends Shape {
    public Rect(int x1, int y1, int x2, int y2) {
        super(x1,y1,x2,y2);
        this.setColor1(Color.BLACK);
        this.setColor2(Color.BLACK);
        this.setFilled(false);
        this.setStrokeWidth(10);
        this.setGradient(false);
    }
    public Rect(int x1, int y1, int x2, int y2, Color color1, Color color2, Boolean filled, int strokeWidth, Boolean gradient)
    {
        this(x1, y1, x2, y2);
        this.setColor1(color1);
        this.setColor2(color2);
        this.setFilled(filled);
        this.setStrokeWidth(strokeWidth);
        this.setGradient(gradient);
    }
    public Rect (Rect src)
    {
        this.x1 = src.x1;
        this.y1 = src.y1;
        this.x2 = src.x2;
        this.y2 = src.y2;
        this.color1 = src.color1;
        this.color2 = src.color2;
        this.filled = src.filled;
        this.strokeWidth = src.strokeWidth;
        this.gradient = src.gradient;
    }
    public void setPointer(int x1, int y1, int x2, int y2){
        this.x1 = x1;
        this.x2 = x2;
        this.y1 = y1;
        this.y2 = y2;
    }
    public void draw(Graphics G) {
        if(!this.visible) return;
        Graphics2D g2d = (Graphics2D)G;
        g2d.setStroke(new BasicStroke(strokeWidth));
        if (gradient) g2d.setPaint(new GradientPaint(10,10,color1,20,20,color2,true));
        else g2d.setColor(this.color1);
        if (filled) G.fillRect(Math.min(x1, x2), Math.min(y1, y2), Math.abs(x1 - x2), Math.abs(y1 - y2));
        else G.drawRect(Math.min(x1, x2), Math.min(y1, y2), Math.abs(x1 - x2), Math.abs(y1 - y2));
    }

    public static Rect generateRandomRect()
    {
        Random rnd = new Random();
        int x1, x2, y1, y2, R, G, B;
        x1 = rnd.nextInt(1000);
        x2 = rnd.nextInt(1000);
        y1 = rnd.nextInt(700);
        y2 = rnd.nextInt(700);
        R = rnd.nextInt(255);
        G = rnd.nextInt(255);
        B = rnd.nextInt(255);

        Rect rect = new Rect(x1, y1, x2, y2);
        rect.setColor1(new Color(R, G, B));
        rect.setFilled(rnd.nextBoolean());

        return rect;
    }
}
