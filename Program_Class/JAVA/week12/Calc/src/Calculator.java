import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.HashMap;
import java.util.Map;

/**
 * Created by Ikaros on 2015/5/18.
 */
public class Calculator extends JFrame implements ActionListener{
    String Operator;
    double calcValue, tmpValue;
    public Calculator(){
        JPanel numberPanel = new JPanel();
        GridBagLayout GBLayout = new GridBagLayout();
        Map<String, int[]> CompAttrMap = new HashMap<>();
        Map<String, JButton> BtnMap = new HashMap<>();

        CompAttrMap.put("C", new int[]{0,1,1,1});
        CompAttrMap.put("+-", new int[]{1,1,1,1});
        CompAttrMap.put("/", new int[]{2, 1, 1, 1});
        CompAttrMap.put("*", new int[]{3, 1, 1, 1});
        CompAttrMap.put("-", new int[]{3, 2, 1, 1});
        CompAttrMap.put("+", new int[]{3, 3, 1, 1});
        CompAttrMap.put("=", new int[]{3, 4, 1, 2});
        CompAttrMap.put(".", new int[]{2, 5, 1, 1});
        CompAttrMap.put("0", new int[]{0, 5, 2, 1});
        CompAttrMap.put("1", new int[]{0, 4, 1, 1});
        CompAttrMap.put("2", new int[]{1, 4, 1, 1});
        CompAttrMap.put("3", new int[]{2, 4, 1, 1});
        CompAttrMap.put("4", new int[]{0, 3, 1, 1});
        CompAttrMap.put("5", new int[]{1, 3, 1, 1});
        CompAttrMap.put("6", new int[]{2, 3, 1, 1});
        CompAttrMap.put("7", new int[]{0, 2, 1, 1});
        CompAttrMap.put("8", new int[]{1, 2, 1, 1});
        CompAttrMap.put("9", new int[]{2, 2, 1, 1});

        numberPanel.setLayout(GBLayout);
        GBLayout.columnWidths = new int[]{80,80,80,80};
        GBLayout.rowHeights = new int[]{80,80,80,80,80,80};

        BtnMap.put("C", new JButton("C"));
        BtnMap.put("+-",new JButton("+-"));
        BtnMap.put("/", new JButton("/"));
        BtnMap.put("*", new JButton("*"));
        BtnMap.put("-", new JButton("-"));
        BtnMap.put("+", new JButton("+"));
        BtnMap.put("=", new JButton("="));
        BtnMap.put(".", new JButton("."));
        BtnMap.put("0", new JButton("0"));
        BtnMap.put("1", new JButton("1"));
        BtnMap.put("2", new JButton("2"));
        BtnMap.put("3", new JButton("3"));
        BtnMap.put("4", new JButton("4"));
        BtnMap.put("5", new JButton("5"));
        BtnMap.put("6", new JButton("6"));
        BtnMap.put("7", new JButton("7"));
        BtnMap.put("8", new JButton("8"));
        BtnMap.put("9", new JButton("9"));

        for(JButton btn : BtnMap.values())
        {
            GridBagConstraints Constraints = new GridBagConstraints();
            Constraints.gridx = CompAttrMap.get(btn.getText())[0];
            Constraints.gridy = CompAttrMap.get(btn.getText())[1];
            Constraints.gridwidth = CompAttrMap.get(btn.getText())[2];
            Constraints.gridheight = CompAttrMap.get(btn.getText())[3];
            Constraints.fill = GridBagConstraints.BOTH;
            btn.addActionListener(this);
            numberPanel.add(btn,Constraints);
        }
        add(numberPanel);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        Operator = ((JButton) e.getSource()).getText();
        switch(Operator)
        {
            case "C": calcValue = 0; break;
            case "+-": calcValue *= -1; break;
        }
    }
}
