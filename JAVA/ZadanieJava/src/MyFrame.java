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



        //PANEL WPISZ LOGIN I PASSWORD
        JPanel NorthPanel = new JPanel();
        NorthPanel.setBackground(new Color(0xfffaaa));
        //grid
        GridLayout NorthLayout = new GridLayout(2, 2, 2, 12);
        NorthPanel.setLayout(NorthLayout);

        JLabel JLLogin = new JLabel("Login");
        JLabel JLPassword = new JLabel("Password");
        final JTextField JTLogin = new JTextField();
        final JPasswordField JTPassword = new JPasswordField();
        NorthPanel.add(JLLogin);
        NorthPanel.add(JTLogin);
        NorthPanel.add(JLPassword);
        NorthPanel.add(JTPassword);



        //Panel TEXT AREA
        JTextArea JTArea = new JTextArea();
        JScrollPane JSP = new JScrollPane(JTArea);



        //PANEL INSERT
        JPanel SouthPanel = new JPanel();
        JButton InsertButton = new JButton("INSERT");
        SouthPanel.add(InsertButton);

        InsertButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

                JTArea.append("Username: "+JTLogin.getText() + " Password: "+ new String(JTPassword.getPassword())+"\n");
            }
        });


        // Add NorthPanel na pozycji NORTH
        MainPanel.add(NorthPanel, BorderLayout.NORTH);
        MainPanel.add(JSP, BorderLayout.CENTER);
        MainPanel.add(SouthPanel,BorderLayout.SOUTH);

        this.add(MainPanel);
        this.setVisible(true);
    }
}
