import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.*;
public class MyFrame extends JFrame {
    //guziki
    private JPanel ButtonsPanel;
    private JTextArea Equasion;
    private ActionListener wstaw;
    private ActionListener oblicz;
    private boolean start = true;
    private double score;
    MyFrame() {
        //FRAME
        this.setTitle("Kalkulatorek");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setResizable(false);
        this.setSize(700, 700);


        Equasion = new JTextArea();
        Equasion.setText("WYNIK");
        Equasion.setFont(new Font("Arial", Font.PLAIN, 48));

        ButtonsPanel = new JPanel();
        ButtonsPanel.setLayout(new GridLayout(4,4,10,10));

        AddButton("7", wstaw );
        AddButton("8", null);
        AddButton("9", null);
        AddButton("/", null);

        AddButton("4", null);
        AddButton("5", null);
        AddButton("6", null);
        AddButton("*", null);

        AddButton("1", null);
        AddButton("2", null);
        AddButton("3", null);
        AddButton("-", null);

        AddButton("0", null);
        AddButton(".", null);
        AddButton("=", null);
        AddButton("+", null);

        this.add(Equasion, BorderLayout.NORTH);
        this.add(ButtonsPanel, BorderLayout.CENTER);
        this.setVisible(true);
    }
    private void AddButton(String name, ActionListener event) {
        JButton button = new JButton(name);
        button.setFont(new Font("Arial", Font.PLAIN, 24));
        wstaw = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(start){
                    Equasion.setText("");
                    Equasion.append(button.getText());
                    start = false;
                }
                else{
                    Equasion.append(button.getText());
                }
            }
        };


        oblicz = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

            }
        };


        button.addActionListener(wstaw);
        ButtonsPanel.add(button);
    }
}