package net.hsexpert;
import java.awt.*;

/**

 * Created by ikaros on 2015/3/17.
 */
public abstract class Shape {
    protected int x1, y1, x2, y2;
    protected Color color;
    protected Boolean filled;
    protected Boolean visible = true;

    public abstract void draw(Graphics G);

    public Color getColor() {
        return color;
    }

    public void setColor(Color color) {
        this.color = color;
    }

    public Shape() {
    }

    public Shape(int x1, int y1, int x2, int y2) {
        this.x1 = x1;
        this.y1 = y1;
        this.x2 = x2;
        this.y2 = y2;
    }

    public Boolean isFilled() {
        return filled;
    }

    public void setFilled(Boolean filled) {
        this.filled = filled;
    }

    public Boolean getVisible() {
        return visible;
    }

    public void setVisible(Boolean visible) {
        this.visible = visible;
    }
}
