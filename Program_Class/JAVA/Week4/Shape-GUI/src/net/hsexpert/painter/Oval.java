package net.hsexpert.painter;

import java.awt.*;
import java.util.Random;

/**
 * Created by ikaros on 2015/4/7.
 */
public class Oval extends Shape{
    protected int width, height;
    public Oval(int x1, int y1, int width, int height) {
        this.setPointer(x1,y1,width,height);
        this.setColor1(Color.BLACK);
        this.setColor2(Color.BLACK);
        this.setFilled(false);
        this.setStrokeWidth(10);
        this.setGradient(false);
    }
    public Oval(int x1, int y1, int width, int height, Color color1, Color color2, Boolean filled, int strokeWidth, Boolean gradient){
        this.setPointer(x1, y1, width, height);
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
    public void setPointer(int x1, int y1, int x2, int y2){
        this.x1 = Math.min(x1,x2);
        this.y1 = Math.min(y1,y2);
        this.width = Math.abs(x2-x1);
        this.height = Math.abs(y2-y1);
    }
    public static Oval generateRandomOval()
    {
        Random rnd = new Random();
        int x1, y1, width, height, R1, G1, B1, R2, G2, B2;
        x1 = rnd.nextInt(1280);
        y1 = rnd.nextInt(1280);
        width = rnd.nextInt(720);
        height = rnd.nextInt(720);
        R1 = rnd.nextInt(255);
        G1 = rnd.nextInt(255);
        B1 = rnd.nextInt(255);
        R2 = rnd.nextInt(255);
        G2 = rnd.nextInt(255);
        B2 = rnd.nextInt(255);

        Oval oval = new Oval(x1, y1, width, height);
        oval.setColor1(new Color(R1, G1, B1));
        oval.setColor2(new Color(R2, G2, B2));
        oval.setFilled(rnd.nextBoolean());
        oval.setGradient(rnd.nextBoolean());


        return oval;
    }

}
