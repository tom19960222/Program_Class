package net.hsexpert.TicTacToe;

import net.hsexpert.painter.Shape;

import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;

/**
 * Created by Ikaros on 2015/4/21.
 */
public class DrawPanel extends JPanel {
    static ArrayList<Shape> ShapeList = new ArrayList<Shape>();

    public DrawPanel()
    {
    }
    private void drawBase(Graphics g)
    {
        Graphics2D g2d = ((Graphics2D) g);
        g2d.setStroke(new BasicStroke(12f));
        g2d.drawLine(300, 200, 900, 200);
        g2d.drawLine(300, 400, 900, 400);
        g2d.drawLine(500,50,500,550);
        g2d.drawLine(700,50,700,550);

    }
    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        drawBase(g);
        for(Shape S : ShapeList)
            S.draw(g);
    }

    @Override
    public void repaint() {
        super.repaint();
    }
}
