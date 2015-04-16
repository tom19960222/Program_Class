package net.hsexpert;

import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.util.*;


/**
 * Created by ikaros on 2015/3/17.
 */
public class DrawPanel extends JPanel implements MouseListener, MouseMotionListener {

    java.util.List<Shape> ShapeList = new ArrayList<Shape>();
    int x1, y1, x2, y2;
    Shape DragShape;
    Boolean Dragging = false;

    public void drawAll(Graphics G)
    {
        for (Shape S : ShapeList)
            S.draw(G);
    }
    public void paintTest()
    {
        for(int i = 0; i < 1000; i++)
        {
            if(i % 3 == 0) ShapeList.add(Rect.generateRandomRect());
            else if (i % 3 == 1) ShapeList.add(Triangle.generateRandomTriangle());
            else ShapeList.add(Oval.generateRandomOval());
        }
        repaint();
    }

    @Override
    public void paintComponent(Graphics G)
    {
        super.paintComponent(G);
        drawAll(G);
    }

    @Override
    public void mouseClicked(MouseEvent e) {

    }

    @Override
    public void mousePressed(MouseEvent e) {
        x1 = e.getX();
        y1 = e.getY();
    }

    @Override
    public void mouseReleased(MouseEvent e) {
        Dragging = false;
        x2 = e.getX();
        y2 = e.getY();
        Rect R = new Rect(x1, y1, x2, y2);
        ShapeList.add(R);
        ShapeList.remove(DragShape);
        repaint();
    }

    @Override
    public void mouseEntered(MouseEvent e) {

    }

    @Override
    public void mouseExited(MouseEvent e) {

    }

    @Override
    public void mouseDragged(MouseEvent e) {
        if (!Dragging) {
            Dragging = true;
            x2 = e.getX();
            y2 = e.getY();
            DragShape = new Rect(x1, y1, x2, y2);
            ShapeList.add(DragShape);
            repaint();
        }
        else {
            x2 = e.getX();
            y2 = e.getY();
            DragShape.x1 = x1;
            DragShape.x2 = x2;
            DragShape.y1 = y1;
            DragShape.y2 = y2;
            repaint();
        }
    }

    @Override
    public void mouseMoved(MouseEvent e) {

    }
}
