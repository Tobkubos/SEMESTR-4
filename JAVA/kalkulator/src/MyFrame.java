import javax.script.ScriptEngine;
import javax.script.ScriptEngineManager;
import javax.script.ScriptException;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MyFrame extends JFrame {
    private ScriptEngine engine;

    MyFrame() {
        this.setTitle("Kalkulator");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setSize(300, 300);

        // Inicjalizacja ScriptEngine
        ScriptEngineManager manager = new ScriptEngineManager();
        this.engine = manager.getEngineByName("JavaScript");

        JPanel mainPanel = new JPanel();
        mainPanel.setLayout(new BorderLayout());

        //Guziki
        JPanel buttonsPanel = new JPanel();
        buttonsPanel.setLayout(new GridLayout(4, 4, 5, 5));

        //guziki konstruktor
        JButton one = new JButton("1");
        JButton two = new JButton("2");
        JButton three = new JButton("3");
        JButton four = new JButton("4");
        JButton five = new JButton("5");
        JButton six = new JButton("6");
        JButton seven = new JButton("7");
        JButton eight = new JButton("8");
        JButton nine = new JButton("9");
        JButton comma = new JButton(".");

        JButton plus = new JButton("+");
        JButton minus = new JButton("-");
        JButton division = new JButton("/");
        JButton multiplication = new JButton("*");
        JButton clear = new JButton("C");
        JButton score = new JButton("=");

        buttonsPanel.add(one);
        buttonsPanel.add(two);
        buttonsPanel.add(three);
        buttonsPanel.add(four);
        buttonsPanel.add(five);
        buttonsPanel.add(six);
        buttonsPanel.add(seven);
        buttonsPanel.add(eight);
        buttonsPanel.add(nine);
        buttonsPanel.add(comma);
        buttonsPanel.add(plus);
        buttonsPanel.add(minus);
        buttonsPanel.add(division);
        buttonsPanel.add(multiplication);
        buttonsPanel.add(clear);
        buttonsPanel.add(score);

        JTextArea resultTextArea = new JTextArea();

        ActionListener numberListener = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JButton button = (JButton) e.getSource();
                resultTextArea.append(button.getText());
            }
        };

        one.addActionListener(numberListener);
        two.addActionListener(numberListener);
        three.addActionListener(numberListener);
        four.addActionListener(numberListener);
        five.addActionListener(numberListener);
        six.addActionListener(numberListener);
        seven.addActionListener(numberListener);
        eight.addActionListener(numberListener);
        nine.addActionListener(numberListener);
        comma.addActionListener(numberListener);

        plus.addActionListener(numberListener);
        minus.addActionListener(numberListener);
        division.addActionListener(numberListener);
        multiplication.addActionListener(numberListener);

        clear.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                resultTextArea.setText("");
            }
        });


        mainPanel.add(resultTextArea, BorderLayout.NORTH);
        mainPanel.add(buttonsPanel, BorderLayout.CENTER);
        this.add(mainPanel);
        this.setLocationRelativeTo(null);
        this.setVisible(true);
    }
}