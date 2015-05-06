package net.hsexpert.TicTacToe;

import java.util.ArrayList;
import java.util.List;
import javax.swing.*;
import java.awt.*;


/**
 * Created by Ikaros on 2015/4/21.
 */
public class TicTacToePanel extends JPanel{


    static DrawPanel drawPanel;
    ButtonPanel buttonPanel;
    MouseActionProcesser MAP = new MouseActionProcesser();
    static List<JPanel> repaintPanelList = new ArrayList<JPanel>();
    public TicTacToePanel()
    {
        setLayout(new BorderLayout());
        drawPanel = new DrawPanel();
        buttonPanel = new ButtonPanel();

        drawPanel.addMouseListener(MAP);

        this.add(drawPanel, BorderLayout.CENTER);
        this.add(buttonPanel, BorderLayout.SOUTH);
    }
    public void repaintDrawPanel() {drawPanel.repaint();}
}
