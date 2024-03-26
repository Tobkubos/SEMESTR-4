import  javax.swing.*;
import java.awt.*;
import java.awt.event.ItemListener;

public class Tool extends JFrame{
        // toolbar
        static JToolBar toolbar;

        // buttons
        static JButton b1, b2, b3;

        // create a frame
        static JFrame frame;

    public static void main(String[] args) {
        frame = new JFrame("TOOL BAR");
        frame.setLayout(new BorderLayout());
        toolbar = new JToolBar();
        JPanel panel = new JPanel();

        b1 = new JButton("zmien tlo");
        b2 = new JButton("narysuj obrazek");
        b3 = new JButton("usun system");

        panel.add(b1);
        panel.add(b2);
        panel.add(b3);
        //b1.addActionListener();

        toolbar.add(panel);

        frame.add(toolbar, BorderLayout.NORTH);

        frame.setSize(500,500);
        frame.setVisible(true);
    }
}