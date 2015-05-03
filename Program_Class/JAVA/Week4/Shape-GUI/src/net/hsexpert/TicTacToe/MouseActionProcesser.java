package net.hsexpert.TicTacToe;

import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;

/**
 * Created by Ikaros on 2015/4/21.
 */
public class MouseActionProcesser implements MouseListener, MouseMotionListener{
    public MouseActionProcesser() {
    }

    @Override
    public void mouseClicked(MouseEvent e) {
        System.out.println(e.getPoint());
        //DrawPanel.ShapeList.add(new Cross(e.getX(), e.getY()));
        Circle C = new Circle(e.getX(),e.getY(),60);
        DrawPanel.ShapeList.add(C);
        TicTacToePanel.drawPanel.repaint();
    }

    @Override
    public void mousePressed(MouseEvent e) {

    }

    @Override
    public void mouseReleased(MouseEvent e) {

    }

    @Override
    public void mouseEntered(MouseEvent e) {

    }

    @Override
    public void mouseExited(MouseEvent e) {

    }

    @Override
    public void mouseDragged(MouseEvent e) {

    }

    @Override
    public void mouseMoved(MouseEvent e) {

    }
}
