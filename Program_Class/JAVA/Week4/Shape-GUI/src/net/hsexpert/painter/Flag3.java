package net.hsexpert.painter;

import java.awt.*;

/**
 * Created by Ikaros on 2015/5/6.
 */
public class Flag3 extends Rect {
    Color color3;
    int height, onethirdWidth;

    public Flag3(int x1, int y1, int x2, int y2) {
        super(x1, y1, x2, y2);
        color3 = Color.BLACK;
    }

    public Flag3(int x1, int y1, int x2, int y2, Color color1, Color color2, Color color3, Boolean filled, int strokeWidth, Boolean gradient) {
        super(x1, y1, x2, y2, color1, color2, filled, strokeWidth, gradient);
        this.color3 = color3;
    }

    public Flag3(Flag3 src) {
        super(src);
        this.color3 = src.color3;
        this.height = src.height;
        this.onethirdWidth = src.onethirdWidth;
    }

    @Override
    public void draw(Graphics G) {
        if(!this.visible) return;
        Graphics2D g2d = (Graphics2D)G;
        g2d.setColor(this.color1);
        g2d.fillRect(x1, y1, onethirdWidth, height);
        g2d.setColor(this.color2);
        g2d.fillRect(x1+onethirdWidth, y1, onethirdWidth, height);
        g2d.setColor(this.color3);
        g2d.fillRect(x1+onethirdWidth*2, y1, onethirdWidth, height);
    }

    @Override
    public void setPointer(int x1, int y1, int x2, int y2) {
        this.x1 = Math.min(x1,x2);
        this.y1 = Math.min(y1, y2);
        onethirdWidth = Math.abs(x1-x2)/3;
        height = Math.abs(y1 - y2);
    }
}
