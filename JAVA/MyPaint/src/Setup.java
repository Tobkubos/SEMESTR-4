import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Setup extends JFrame {

    Setup(){

        setSize(300,300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JButton Start = new JButton("Start");

        Start.addActionListener(e -> {
            setVisible(false);
            new PaintPanel(700,700);});
        add(Start);

        setVisible(true);
        };
    }
