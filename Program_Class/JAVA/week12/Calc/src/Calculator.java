import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;

/**
 * Created by Ikaros on 2015/5/18.
 */
public class Calculator extends JFrame {
    private int[][] NumberBtnArr = new int[][] {
            {0,5,2,1},
            {0,4,1,1},
            {1,4,1,1},
            {2,4,1,1},
            {0,3,1,1},
            {1,3,1,1},
            {2,3,1,1},
            {0,2,1,1},
            {1,2,1,1},
            {2,2,1,1}
    };
    private int[][] FuncBtnArr = new int[][]{
            {0,1,1,1},
            {1,1,1,1},
            {2,1,1,1},
            {3,1,1,1},
            {3,2,1,1},
            {3,3,1,1},
            {3,4,1,2},
            {2,5,1,1}
    };
    public Calculator(){
        JPanel numberPanel = new JPanel();
        GridBagLayout GBLayout = new GridBagLayout();
        GridBagConstraints gbc = new GridBagConstraints();
        ArrayList<JButton> btnList = new ArrayList<JButton>();

        numberPanel.setLayout(GBLayout);
        GBLayout.columnWidths = new int[]{80,80,80,80};
        GBLayout.rowHeights = new int[]{80,80,80,80,80,80};

        btnList.add(new JButton("C"));
        btnList.add(new JButton("+-"));
        btnList.add(new JButton("/"));
        btnList.add(new JButton("*"));
        btnList.add(new JButton("-"));
        btnList.add(new JButton("+"));
        btnList.add(new JButton("="));
        btnList.add(new JButton("."));

        for(int i = 0; i < btnList.size(); i++)
        {
            GridBagConstraints Constraints = new GridBagConstraints();
            Constraints.gridx = FuncBtnArr[i][0];
            Constraints.gridy = FuncBtnArr[i][1];
            Constraints.gridwidth = FuncBtnArr[i][2];
            Constraints.gridheight = FuncBtnArr[i][3];
            Constraints.fill = GridBagConstraints.BOTH;
            numberPanel.add(btnList.get(i),Constraints);
        }

        for (int i = 0; i <= 9; i++)
        {
            JButton btn = new JButton(String.valueOf(i));
            GridBagConstraints Constraints = new GridBagConstraints();
            Constraints.gridx = NumberBtnArr[i][0];
            Constraints.gridy = NumberBtnArr[i][1];
            Constraints.gridwidth = NumberBtnArr[i][2];
            Constraints.gridheight = NumberBtnArr[i][3];
            Constraints.fill = GridBagConstraints.BOTH;
            numberPanel.add(btn, Constraints);
        }

        add(numberPanel);
    }
}
