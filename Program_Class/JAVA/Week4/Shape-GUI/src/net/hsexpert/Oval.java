package net.hsexpert;

import java.awt.*;
import java.util.Random;

/**
 * Created by ikaros on 2015/4/7.
 */
public class Oval extends Shape{
    int width, height;
    public Oval(int x1, int y1, int width, int height) {
        super(x1,y1,0,0);
        this.width = width;
        this.height = height;
        this.color1 = Color.BLACK;
        this.color2 = Color.BLACK;
        this.filled = false;
        this.setStrokeWidth(10);
        this.setGradient(false);
    }
    public Oval(int x1, int y1, int width, int height, Color color1, Color color2, Boolean filled, int strokeWidth, Boolean gradient){
        this(x1, y1, width, height);
        this.setColor1(color1);
        this.setColor2(color2);
        this.setFilled(filled);
        this.setStrokeWidth(strokeWidth);
        this.setGradient(gradient);
    }
    public Oval(Oval src)
    {
        this.x1 = src.x1;
        this.y1 = src.y1;
        this.width = src.width;
        this.height = src.height;
        this.filled = src.filled;
        this.color1 = src.color1;
        this.color2 = src.color2;
        this.strokeWidth = src.strokeWidth;
        this.gradient = src.gradient;
    }
    @Override
    public void draw(Graphics G) {
        if(!this.visible) return;
        Graphics2D g2d = (Graphics2D)G;
        g2d.setStroke(new BasicStroke(strokeWidth));
        if (gradient) g2d.setPaint(new GradientPaint(10,10,color1,20,20,color2,true));
        else g2d.setColor(this.color1);
        if(this.filled)
            g2d.fillOval(x1, y1, width, height);
        else
            g2d.drawOval(x1, y1, width, height);
    }
    public void setPointer(int x1, int y1, int width, int height){
        this.x1 = x1;
        this.width = width;
        this.y1 = y1;
        this.height = height;
    }
    public static Oval generateRandomOval()
    {
        Random rnd = new Random();
        int x1, y1,width, height, R, G, B;
        x1 = rnd.nextInt(1280);
        y1 = rnd.nextInt(720);
        width = rnd.nextInt(1280);
        height = rnd.nextInt(720);
        R = rnd.nextInt(255);
        G = rnd.nextInt(255);
        B = rnd.nextInt(255);

        Oval Ova = new Oval(x1, y1, width, height);
        Ova.setColor1(new Color(R, G, B));
        Ova.setFilled(rnd.nextBoolean());

        return Ova;
    }

}
