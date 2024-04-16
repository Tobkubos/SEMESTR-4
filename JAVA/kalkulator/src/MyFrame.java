import javax.swing.*;
import javax.swing.border.Border;
import javax.swing.border.EmptyBorder;
import javax.swing.border.LineBorder;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.nio.charset.MalformedInputException;
import java.util.Random;

public class MyFrame extends JFrame {
    MyFrame() {
        //FRAME
        this.setTitle("Okienko okienko okienko");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setResizable(true);
        this.setSize(700, 700);

        //PANEL GLOWNY
        JPanel MainPanel = new JPanel();
        MainPanel.setLayout(new BorderLayout());

        // GUZIKI
        JPanel Buttons = new JPanel();
        GridLayout GL = new GridLayout(4,4,5,5);
        Buttons.setLayout(GL);

        JButton one = new JButton("1");
        JButton two = new JButton("2");
        JButton three = new JButton("3");
        JButton four = new JButton("4");
        JButton five = new JButton("5");
        JButton six = new JButton("6");
        JButton seven = new JButton("7");
        JButton eight = new JButton("8");
        JButton nine = new JButton("9");

        JButton plus = new JButton("+");
        JButton minus = new JButton("-");
        JButton division = new JButton("/");
        JButton multiplicate = new JButton("*");
        JButton clear = new JButton("C");
        JButton score = new JButton("=");

        Buttons.add(one);
        Buttons.add(two);
        Buttons.add(three);
        Buttons.add(one);


        MainPanel.add(Buttons);
        //
        this.add(MainPanel);
        this.setVisible(true);
    }
}
