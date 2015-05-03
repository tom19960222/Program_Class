package net.hsexpert.TicTacToe;

import net.hsexpert.painter.Line;
import net.hsexpert.painter.Shape;

import java.awt.*;

/**
 * Created by Ikaros on 2015/5/3.
 */
public class Cross extends Shape {
    Line LeftUptoRightDown, RightUptoLeftDown;
    int halfLineLength = 50;

    public Cross(int x,int y) {
        LeftUptoRightDown = new Line(x-halfLineLength,y-halfLineLength,x+halfLineLength,y+halfLineLength);
        RightUptoLeftDown = new Line(x+halfLineLength,y-halfLineLength,x-halfLineLength,y+halfLineLength);
    }

    public Cross(int x,int y, int halfLineLength)
    {
        this.halfLineLength = halfLineLength;
        LeftUptoRightDown = new Line(x-halfLineLength,y-halfLineLength,x+halfLineLength,y+halfLineLength);
        RightUptoLeftDown = new Line(x+halfLineLength,y-halfLineLength,x-halfLineLength,y+halfLineLength);
    }
    public Cross(int x1, int y1, int x2, int y2)
    {
        /*LeftUptoRightDown = new Line(x-halfLineLength,y-halfLineLength,x+halfLineLength,y+halfLineLength);
        RightUptoLeftDown = new Line(x+halfLineLength,y+halfLineLength,x-halfLineLength,y-halfLineLength);*/
    }

    @Override
    public void setPointer(int x1, int y1, int x2, int y2) {

    }

    public void draw(Graphics G) {
        LeftUptoRightDown.draw(G);
        RightUptoLeftDown.draw(G);
    }

    public void setPointer(int x, int y) {
        LeftUptoRightDown.setPointer(x-halfLineLength,y-halfLineLength,x+halfLineLength,y+halfLineLength);
        RightUptoLeftDown.setPointer(x+halfLineLength,y-halfLineLength,x-halfLineLength,y+halfLineLength);
    }



}
