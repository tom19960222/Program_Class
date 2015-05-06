package net.hsexpert.painter;

import java.awt.*;

/**
 * Created by Ikaros on 2015/5/6.
 */
public class Circle3 extends Oval {
    protected int radius, divwidth;
    protected Color color3;

    public Circle3(int x1, int y1, int x2, int y2) {
        super(x1, y1, x2, y2);
        color3 = Color.BLACK;
    }

    @Override
    public void setPointer(int x1, int y1, int x2, int y2) {
        super.setPointer(x1, y1, x2, y2);
        radius = ((int) Math.sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)))/2);
        divwidth = ((int) (Math.abs(x1 - x2) / 6));

    }

    public Circle3(int x1, int y1, int x2, int y2, Color color1, Color color2, Color color3, Boolean filled, int strokeWidth, Boolean gradient) {
        super(x1, y1, x2, y2, color1, color2, filled, strokeWidth, gradient);
        this.color3 = color3;
    }

    public Circle3(Circle3 src) {
        super(src);
        radius = src.radius;
        divwidth = src.divwidth;
        color3 = src.color3;
    }

    @Override
    public void draw(Graphics G) {
        if(!this.visible) return;
        Graphics2D g2d = (Graphics2D)G;
        g2d.setStroke(new BasicStroke(strokeWidth));
        if (gradient) g2d.setPaint(new GradientPaint(10,10,color1,20,20,color2,true));
        else g2d.setColor(this.color1);
        if(this.filled)
            g2d.fillOval(x1, y1, 2*radius, 2*radius);
        else
            g2d.drawOval(x1, y1, 2*radius, 2*radius);
        g2d.setColor(this.color2);
        g2d.fillOval(x1+divwidth, y1+divwidth, 2*radius-2*divwidth, 2*radius-2*divwidth);
        g2d.setColor(this.color3);
        g2d.fillOval(x1+divwidth*2, y1+divwidth*2, 2*radius-4*divwidth, 2*radius-4*divwidth);
    }
}
