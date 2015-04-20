package net.hsexpert;

import javax.swing.*;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * Created by ikaros on 2015/3/23.
 */
public class DrawFrame extends JFrame implements ActionListener, ChangeListener{
    public DrawPanel DrawPanel;
    public JPanel BottomPanel;
    public JPanel ActionPanel;
    public JPanel ShapePanel;
    public JPanel ColorPanel;
    private JButton btnClear;
    private JButton btnUndo;
    private JButton btnRedo;
    private JButton btnRandomGenerate;
    private JButton btnRect;
    private JButton btnTriangle;
    private JButton btnOval;
    private JButton btnLine;
    private JButton btnCustomShape;
    private JButton btnColor1;
    private JButton btnColor2;
    private JCheckBox chkGradient;
    private JCheckBox chkFilled;
    private JSlider slideStroke;
    private JLabel labelStroke;

    public enum Shape {Rect, Triangle, Oval, Line, Custom};

    public static Color Color1 = new Color(0,0,0);
    public static Color Color2 = new Color(0,0,0);
    public static Boolean drawGradient = false, drawFilled = false;
    public static int strokeWidth;
    public static Shape CurrentShape = Shape.Rect;

    public DrawFrame() throws HeadlessException {
        DrawPanel = new DrawPanel();
        BottomPanel = new JPanel(new GridLayout(2,2));
        ActionPanel = new JPanel(new GridLayout(1,4));
        ShapePanel = new JPanel(new GridLayout(1,4));
        ColorPanel = new JPanel(new GridLayout(1,2));
        btnClear = new JButton("Clear");
        btnUndo = new JButton("Undo");
        btnRedo = new JButton("Redo");
        btnRandomGenerate = new JButton("RandGen");
        btnRect = new JButton("Rect");
        btnOval = new JButton("Oval");
        btnTriangle = new JButton("Triangle");
        btnLine = new JButton("Line");
        btnCustomShape = new JButton("Custom");
        btnColor1 = new JButton("Color1");
        btnColor2 = new JButton("Color2");
        chkGradient = new JCheckBox("Gradient");
        chkFilled = new JCheckBox("Filled");
        slideStroke = new JSlider(1,20,10);
        labelStroke = new JLabel();

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
        ColorPanel.add(chkGradient);
        ColorPanel.add(chkFilled);
        ColorPanel.add(slideStroke);
        ColorPanel.add(labelStroke);

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
        chkGradient.addActionListener(this);
        chkFilled.addActionListener(this);
        slideStroke.addChangeListener(this);

        btnRandomGenerate.addActionListener(this);
        btnClear.addActionListener(this);
        btnUndo.addActionListener(this);
        btnRedo.addActionListener(this);

        this.addMouseListener(DrawPanel);
        this.addMouseMotionListener(DrawPanel);
        updateButton();
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if(e.getSource() == btnRandomGenerate){
            DrawPanel.paintTest();

        }
        else if (e.getSource() == btnRect)
        {
            CurrentShape = Shape.Rect;
        }
        else if (e.getSource() == btnTriangle)
        {
            CurrentShape = Shape.Triangle;
        }

        else if (e.getSource() == btnOval)
        {
            CurrentShape = Shape.Oval;
        }
        else if (e.getSource() == btnLine)
        {
            CurrentShape = Shape.Line;
        }
        else if (e.getSource() == btnUndo)
        {
            int i;
            for(i = DrawPanel.ShapeList.size()-1; i >= 0; i--)
                if (DrawPanel.ShapeList.get(i).getVisible()){
                    DrawPanel.ShapeList.get(i).setVisible(false);
                    break;
                }
            DrawPanel.repaint();
        }
        else if (e.getSource() == btnRedo)
        {
            int  i;
            for(i = 0; i < DrawPanel.ShapeList.size(); i++)
                if (!DrawPanel.ShapeList.get(i).getVisible()){
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
        else if (e.getSource() == btnCustomShape)
        {

        }
        else if (e.getSource() == btnColor1)
        {
            Color1 = JColorChooser.showDialog(this, "Choose color1", Color1);
        }
        else if (e.getSource() == btnColor2)
        {
            Color2 = JColorChooser.showDialog(this, "Choose color2", Color2);
        }
        else if (e.getSource() == chkGradient)
        {
            drawGradient = chkGradient.isSelected();
        }
        else if (e.getSource() == chkFilled)
            drawFilled = chkFilled.isSelected();
        updateButton();
    }

    @Override
    public void stateChanged(ChangeEvent e) {
        strokeWidth = slideStroke.getValue();
        updateButton();
    }

    public void updateButton()
    {
        for(Component C : this.ShapePanel.getComponents())
            C.setBackground(new Color(238,238,238)); //Default color1.
        switch(CurrentShape)
        {
            case Rect: btnRect.setBackground(Color.GREEN); break;
            case Triangle: btnTriangle.setBackground(Color.GREEN); break;
            case Oval: btnOval.setBackground(Color.GREEN); break;
            case Line: btnLine.setBackground(Color.GREEN); break;
            case Custom: btnCustomShape.setBackground(Color.GREEN); break;
        }

        if(chkGradient.isSelected()) {
            btnColor2.setEnabled(true);
            drawGradient = true;
        }
        else {
            btnColor2.setEnabled(false);
            drawGradient = false;
        }
        if(chkFilled.isSelected())
            drawFilled = true;
        else
            drawFilled = false;
        btnColor1.setBackground(Color1);
        btnColor2.setBackground(Color2);
        strokeWidth = slideStroke.getValue();
        labelStroke.setText(String.format("Width: %d", strokeWidth));
    }
}
