package net.hsexpert.main;

import net.hsexpert.painter.PainterPanel;
import net.hsexpert.slideDemo.SliderFrame;
import net.hsexpert.TicTacToe.TicTacToePanel;

import javax.swing.*;

/**
 * Created by Ikaros on 2015/4/20.
 */

public class TabFrame extends JFrame {

    JTabbedPane tabPane;
    PainterPanel painterPanel;
    SliderFrame sliderFrame;
    TicTacToePanel ticTacToePanel;

    public TabFrame() {
        tabPane = new JTabbedPane();
        painterPanel = new PainterPanel();
        sliderFrame = new SliderFrame();
        ticTacToePanel = new TicTacToePanel();
        tabPane.addTab("Painter", null, painterPanel);
        tabPane.addTab("SliderDemo", null, sliderFrame);
        tabPane.addTab("TicTacToe", null, ticTacToePanel);
        this.add(tabPane);
    }

}
