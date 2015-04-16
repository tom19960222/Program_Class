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
            this.color = Color.BLACK;
            this.filled = false;
        }
        @Override
        public void draw(Graphics G) {
            if(!this.visible) return;
            Graphics2D g2d = (Graphics2D)G;
            g2d.setColor(this.color);
            if(this.filled)
                g2d.fillOval(x1, y1, width, height);
            else
                g2d.drawOval(x1, y1, width, height);
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
            Ova.setColor(new Color(R, G, B));
            Ova.setFilled(rnd.nextBoolean());

            return Ova;
        }

    }
