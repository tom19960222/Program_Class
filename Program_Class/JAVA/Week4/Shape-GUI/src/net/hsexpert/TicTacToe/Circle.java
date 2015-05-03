package net.hsexpert.TicTacToe;

import net.hsexpert.painter.Shape;
import java.awt.*;

/**
 * Created by Ikaros on 2015/4/21.
 */
public class Circle extends Shape{
    protected int radius;
    public Circle(int x1, int y1, int radius){
        this.x1 = x1-radius;
        this.y1 = y1-radius;
        this.radius = radius;
        this.setColor1(Color.BLACK);
        this.setColor2(Color.BLACK);
        this.setFilled(false);
        this.setStrokeWidth(10);
        this.setGradient(false);
    }

    public Circle(int x1, int y1, int radius, Color color1, Color color2, Boolean filled, int strokeWidth, Boolean gradient) {
        this(x1,y1,radius);
        this.setColor1(color1);
        this.setColor2(color2);
        this.setFilled(filled);
        this.setStrokeWidth(strokeWidth);
        this.setGradient(gradient);
    }

    @Override
    public void draw(Graphics G) {
        if(!this.visible) return;
        Graphics2D g2d = (Graphics2D)G;
        g2d.setStroke(new BasicStroke(strokeWidth));
        if (gradient) g2d.setPaint(new GradientPaint(10,10,color1,20,20,color2,true));
        else g2d.setColor(this.color1);
        if(this.filled)
            g2d.fillOval(x1, y1, radius*2, radius*2);
        else
            g2d.drawOval(x1, y1, radius*2, radius*2);
    }

    @Override
    public void setPointer(int x1, int y1, int x2, int y2) {

    }

/*
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

    @Override
    public void setPointer(int x1, int y1, int x2, int y2) {
        this.x1 = x1;
        this.x2 = x2;
        this.y1 = y1;
        this.y2 = y2;
    }
    */
}
