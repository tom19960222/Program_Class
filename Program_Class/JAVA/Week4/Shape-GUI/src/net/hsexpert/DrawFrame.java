package net.hsexpert;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * Created by ikaros on 2015/3/23.
 */
public class DrawFrame extends JFrame implements ActionListener{
    public DrawPanel DrawPanel;
    public JPanel BottomPanel;
    public JPanel ActionPanel;
    public JPanel ShapePanel;
    public JPanel ColorPanel;
    JButton btnClear;
    JButton btnUndo;
    JButton btnRedo;
    JButton btnRandomGenerate;
    JButton btnRect;
    JButton btnTriangle;
    JButton btnOval;
    JButton btnLine;
    JButton btnCustomShape;
    JButton btnColor1;
    JButton btnColor2;

    enum Shape {Rect, Triangle, Oval, Line, Custom};
    Shape CurrentShape = Shape.Rect;

    public DrawFrame() throws HeadlessException {
        DrawPanel = new DrawPanel();
        BottomPanel = new JPanel();
        ActionPanel = new JPanel(new GridLayout(1,4));
        ShapePanel = new JPanel(new GridLayout(1,4));
        ColorPanel = new JPanel(new GridLayout(1,2));
        btnClear = new JButton("Clear");
        btnUndo = new JButton("Undo");
        btnRedo = new JButton("Redo");
        btnRandomGenerate = new JButton("Random generate");
        btnRect = new JButton("Rect");
        btnOval = new JButton("Oval");
        btnTriangle = new JButton("Triangle");
        btnLine = new JButton("Line");
        btnCustomShape = new JButton("Custom");
        btnColor1 = new JButton("Color1");
        btnColor2 = new JButton("Color2");

        ActionPanel.add(btnClear);
        ActionPanel.add(btnUndo);
        ActionPanel.add(btnRedo);
        ActionPanel.add(btnRandomGenerate);

        ShapePanel.add(btnRect);
        ShapePanel.add(btnTriangle);
        ShapePanel.add(btnOval);
        ShapePanel.add(btnLine);
        ShapePanel.add(btnCustomShape);

        ColorPanel.add(btnColor1);
        ColorPanel.add(btnColor2);

        BottomPanel.add(ActionPanel);
        BottomPanel.add(ShapePanel);
        BottomPanel.add(ColorPanel);
        this.add(DrawPanel, BorderLayout.CENTER);
        this.add(BottomPanel, BorderLayout.SOUTH);

        btnRect.addActionListener(this);
        btnTriangle.addActionListener(this);
        btnOval.addActionListener(this);
        btnLine.addActionListener(this);
        btnCustomShape.addActionListener(this);

        btnColor1.addActionListener(this);
        btnColor2.addActionListener(this);

        btnRandomGenerate.addActionListener(this);
        btnClear.addActionListener(this);
        btnUndo.addActionListener(this);
        btnRedo.addActionListener(this);

        this.addMouseListener(DrawPanel);
        this.addMouseMotionListener(DrawPanel);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if(e.getSource() == btnRandomGenerate){
            DrawPanel.paintTest();
        }
        else if (e.getSource() == btnRect)
        {
            Rect R = Rect.generateRandomRect();
            DrawPanel.ShapeList.add(R);
            DrawPanel.repaint();
        }
        else if (e.getSource() == btnTriangle)
        {
            Triangle T = Triangle.generateRandomTriangle();
            DrawPanel.ShapeList.add(T);
            DrawPanel.repaint();
        }

        else if (e.getSource() == btnOval)
        {
            Oval O = Oval.generateRandomOval();
            DrawPanel.ShapeList.add(O);
            DrawPanel.repaint();
        }
        else if (e.getSource() == btnUndo)
        {
            int  i;
            for(i = DrawPanel.ShapeList.size()-1; i >= 0; i--)
                if (DrawPanel.ShapeList.get(i).getVisible() == true){
                    DrawPanel.ShapeList.get(i).setVisible(false);
                    break;
                }
            DrawPanel.repaint();
        }
        else if (e.getSource() == btnRedo)
        {
            int  i;
            for(i = 0; i < DrawPanel.ShapeList.size(); i++)
                if (DrawPanel.ShapeList.get(i).getVisible() == false){
                    DrawPanel.ShapeList.get(i).setVisible(true);
                    break;
                }
            DrawPanel.repaint();
        }
        else if (e.getSource() == btnClear)
        {
            DrawPanel.ShapeList.clear();
            DrawPanel.repaint();
        }
        else if (e.getSource() == btnLine)
        {

        }
        else if (e.getSource() == btnCustomShape)
        {

        }
        else if (e.getSource() == btnColor1)
        {

        }
        else if (e.getSource() == btnColor2)
        {

        }
    }
    public void updateUI()
    {

    }
}
