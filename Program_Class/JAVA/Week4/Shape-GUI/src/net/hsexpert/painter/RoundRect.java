package net.hsexpert.painter;

        import java.awt.*;
        import java.util.Random;

/**
 * Created by Ikaros on 2015/4/20.
 */
public class RoundRect extends Shape{
    int width, height;
    public RoundRect(int x1, int y1, int width, int height) {
        this.setPointer(x1,y1,width,height);
        this.setColor1(Color.BLACK);
        this.setColor2(Color.BLACK);
        this.setFilled(false);
        this.setStrokeWidth(10);
        this.setGradient(false);
    }
    public RoundRect(int x1, int y1, int width, int height, Color color1, Color color2, Boolean filled, int strokeWidth, Boolean gradient){
        this.setPointer(x1, y1, width, height);
        this.setColor1(color1);
        this.setColor2(color2);
        this.setFilled(filled);
        this.setStrokeWidth(strokeWidth);
        this.setGradient(gradient);
    }
    public RoundRect(RoundRect src)
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
            g2d.fillRoundRect(x1, y1, width, height, ((int) (width * 0.1)), ((int) (height * 0.1)));
        else
            g2d.drawRoundRect(x1, y1, width, height, ((int) (width * 0.1)), ((int) (height * 0.1)));
    }
    public void setPointer(int x1, int y1, int width, int height){
        this.x1 = x1;
        this.y1 = y1;
        this.width = Math.abs(width-x1);
        this.height = Math.abs(height-y1);
    }
    public static RoundRect generateRandomRoundRect()
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

        RoundRect roundRect = new RoundRect(x1, y1, width, height);
        roundRect.setColor1(new Color(R1, G1, B1));
        roundRect.setColor2(new Color(R2, G2, B2));
        roundRect.setFilled(rnd.nextBoolean());
        roundRect.setGradient(rnd.nextBoolean());

        return roundRect;
    }

}
