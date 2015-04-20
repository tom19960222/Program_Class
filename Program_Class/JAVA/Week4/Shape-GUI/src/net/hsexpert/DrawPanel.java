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
        Shape finalShape = new Rect(0,0,0,0);
        switch(DrawFrame.CurrentShape) {
            case Rect: finalShape = new Rect(((Rect) DragShape)); break;
            case Triangle: finalShape = new Triangle(((Triangle) DragShape)); break;
            case Line: finalShape = new Line(((Line) DragShape)); break;
            case Oval: finalShape = new Oval(((Oval) DragShape)); break;
        }
        ShapeList.add(finalShape);
        ShapeList.remove(DragShape);

        DragShape = null;
        finalShape = null;
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

            switch(DrawFrame.CurrentShape) {
                case Rect: DragShape = new Rect(x1,y1,x2,y2,DrawFrame.Color1,DrawFrame.Color2,DrawFrame.drawFilled,DrawFrame.strokeWidth,DrawFrame.drawGradient); break;
                case Triangle: DragShape = new Triangle(x1,y1,x2,y2,DrawFrame.Color1,DrawFrame.Color2,DrawFrame.drawFilled,DrawFrame.strokeWidth,DrawFrame.drawGradient); break;
                case Line: DragShape = new Line(x1,y1,x2,y2,DrawFrame.Color1,DrawFrame.Color2,DrawFrame.drawFilled,DrawFrame.strokeWidth,DrawFrame.drawGradient); break;
                case Oval: DragShape = new Oval(x1,y1,Math.abs(x1-x2), Math.abs(y1-y2),DrawFrame.Color1,DrawFrame.Color2,DrawFrame.drawFilled,DrawFrame.strokeWidth,DrawFrame.drawGradient); break;
            }
            ShapeList.add(DragShape);
            repaint();
        }
        else {
            x2 = e.getX();
            y2 = e.getY();
            switch(DrawFrame.CurrentShape) {
                case Rect: ((Rect) DragShape).setPointer(x1,y1,x2,y2); break;
                case Triangle: ((Triangle) DragShape).setLocationByMouseCoord(x1,y1,x2,y2); break;
                case Line: ((Line) DragShape).setPointer(x1,y1,x2,y2); break;
                case Oval: ((Oval) DragShape).setPointer(x1,y1,Math.abs(x1-x2), Math.abs(y1-y2)); break;
            }
            repaint();
        }
    }

    @Override
    public void mouseMoved(MouseEvent e) {

    }
}
