import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.OutputStream;
import java.util.*;
public class MyFrame extends JFrame {
    private JPanel ButtonsPanel;
    public JTextArea Equasion;

    public String operator;
    public String firstNUmber;
    public boolean first = true;
    public String SecondNumber = "";

    MyFrame() {
        //FRAME
        this.setTitle("Kalkulatorek");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setResizable(false);
        this.setSize(700, 700);


        Equasion = new JTextArea();
        Equasion.setText("");
        Equasion.setFont(new Font("Arial", Font.PLAIN, 48));

        ButtonsPanel = new JPanel();
        ButtonsPanel.setLayout(new GridLayout(4,4,10,10));

        AddButton("7", new WstawLiczbe(this,"7"));
        AddButton("8", new WstawLiczbe(this,"8"));
        AddButton("9", new WstawLiczbe(this,"9"));
        AddButton("/",new WstawOperator(this,"/"));

        AddButton("4", new WstawLiczbe(this,"4"));
        AddButton("5", new WstawLiczbe(this,"5"));
        AddButton("6", new WstawLiczbe(this,"6"));
        AddButton("*", new WstawOperator(this,"*"));

        AddButton("1", new WstawLiczbe(this,"1"));
        AddButton("2", new WstawLiczbe(this,"2"));
        AddButton("3", new WstawLiczbe(this,"3"));
        AddButton("-", new WstawOperator(this,"-"));

        AddButton("0", new WstawLiczbe(this,"0"));
        AddButton(".", new WstawLiczbe(this,"."));
        AddButton("=", new ObliczWynik(this));
        AddButton("+", new WstawOperator(this,"+"));
        AddButton("C", new Clear(this));

        this.add(Equasion, BorderLayout.NORTH);
        this.add(ButtonsPanel, BorderLayout.CENTER);
        this.setVisible(true);
    }
    private void AddButton(String name, ActionListener event) {
        JButton button = new JButton(name);
        button.setFont(new Font("Arial", Font.PLAIN, 24));
        button.addActionListener(event);
        if(name == "C"){
            this.add(button, BorderLayout.SOUTH);
        }
        else{
        ButtonsPanel.add(button);
        }
    }


}