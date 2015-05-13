package net.hsexpert.painter;

import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.util.*;
import java.util.List;


/**
 * Created by ikaros on 2015/3/17.
 */
public class DrawPanel extends JPanel implements MouseListener, MouseMotionListener {

    List<Shape> ShapeList = new ArrayList<Shape>();
    int x1, y1, x2, y2;
    Shape DragShape;
    Boolean Dragging = false;

    public void drawAll(Graphics G)
    {
        for (Shape S : ShapeList)
            S.draw(G);
    }
    private void cleanInvisibleGraphics()
    {
        for(Shape S : ShapeList)
        {
            if(!S.isVisible())
                ShapeList.remove(S);
        }
    }
    private Boolean containsInvisibleGraphics()
    {
        for(Shape S : ShapeList)
        {
            if(S.isVisible())
                return true;
        }
        return false;
    }
    public void paintTest()
    {
        for(int i = 0; i < 1000; i++)
        {
            if(i % 5 == 0) ShapeList.add(Rect.generateRandomRect());
            else if (i % 5 == 1) ShapeList.add(Triangle.generateRandomTriangle());
            else if (i % 5 == 2) ShapeList.add(Oval.generateRandomOval());
            else if (i % 5 == 3) ShapeList.add(Line.generateRandomLine());
            else ShapeList.add(RoundRect.generateRandomRoundRect());
        }
        repaint();
    }
    public void Undo()
    {
        int i;
        for(i = ShapeList.size()-1; i >= 0; i--)
            if (ShapeList.get(i).isVisible()) {
                ShapeList.get(i).setVisible(false);
                break;
            }
    }
    public void Redo()
    {
        int  i;
        for(i = 0; i < ShapeList.size(); i++)
            if (!ShapeList.get(i).isVisible()){
                ShapeList.get(i).setVisible(true);
                break;
            }
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
        cleanInvisibleGraphics(); // When you clicked on drawpanel, you are ready to draw
                                  // , so invisible graphics can be cleared.
        x1 = e.getX();
        y1 = e.getY();
    }

    @Override
    public void mouseReleased(MouseEvent e) {
        Dragging = false;
        x2 = e.getX();
        y2 = e.getY();
        Shape finalShape = new Rect(0,0,0,0);
        switch(PainterPanel.CurrentShape) {
            case Rect: finalShape = new Rect(((Rect) DragShape)); break;
            case Triangle: finalShape = new Triangle(((Triangle) DragShape)); break;
            case Line: finalShape = new Line(((Line) DragShape)); break;
            case Oval: finalShape = new Oval(((Oval) DragShape)); break;
            case Custom: finalShape = new RoundRect(((RoundRect) DragShape)); break;
            case Circle3: finalShape = new Circle3(((Circle3) DragShape)); break;
            case Flag3: finalShape = new Flag3(((Flag3) DragShape)); break;
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

            switch(PainterPanel.CurrentShape) {
                case Rect: DragShape = new Rect(x1,y1,x2,y2, PainterPanel.Color1, PainterPanel.Color2, PainterPanel.drawFilled, PainterPanel.strokeWidth, PainterPanel.drawGradient); break;
                case Triangle: DragShape = new Triangle(x1,y1,x2,y2, PainterPanel.Color1, PainterPanel.Color2, PainterPanel.drawFilled, PainterPanel.strokeWidth, PainterPanel.drawGradient); break;
                case Line: DragShape = new Line(x1,y1,x2,y2, PainterPanel.Color1, PainterPanel.Color2, PainterPanel.drawFilled, PainterPanel.strokeWidth, PainterPanel.drawGradient); break;
                case Oval: DragShape = new Oval(x1,y1,x2,y2, PainterPanel.Color1, PainterPanel.Color2, PainterPanel.drawFilled, PainterPanel.strokeWidth, PainterPanel.drawGradient); break;
                case Custom: DragShape = new RoundRect(x1,y1,x2,y2,PainterPanel.Color1, PainterPanel.Color2, PainterPanel.drawFilled, PainterPanel.strokeWidth, PainterPanel.drawGradient); break;
                case Circle3: DragShape = new Circle3(x1,y1,x2,y2, PainterPanel.Color1, PainterPanel.Color2, Color.BLACK, PainterPanel.drawFilled, PainterPanel.strokeWidth, PainterPanel.drawGradient); break;
                case Flag3: DragShape = new Flag3(x1,y1,x2,y2, PainterPanel.Color1, PainterPanel.Color2, Color.BLACK, PainterPanel.drawFilled, PainterPanel.strokeWidth, PainterPanel.drawGradient); break;
            }
            ShapeList.add(DragShape);
            repaint();
        }
        else {
            x2 = e.getX();
            y2 = e.getY();
            DragShape.setPointer(x1,y1,x2,y2);
            repaint();
        }
    }

    @Override
    public void mouseMoved(MouseEvent e) {

    }
}
