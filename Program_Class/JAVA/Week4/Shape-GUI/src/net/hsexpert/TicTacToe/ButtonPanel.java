package net.hsexpert.TicTacToe;

import javax.swing.*;
import java.awt.*;

/**
 * Created by Ikaros on 2015/4/21.
 */
public class ButtonPanel extends JPanel{
    JButton oButton, xButton;
    ButtonActionProcesser btnActionProcesser;
    MouseActionProcesser mouseActionProcesser;

    public ButtonPanel()
    {
        oButton = new JButton("O");
        xButton = new JButton("X");
        btnActionProcesser = new ButtonActionProcesser();
        mouseActionProcesser = new MouseActionProcesser();

        oButton.addMouseListener(mouseActionProcesser);
        xButton.addMouseListener(mouseActionProcesser);

        this.add(oButton);
        this.add(xButton);
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
    }
}
