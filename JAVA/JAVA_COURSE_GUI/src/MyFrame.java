import javax.swing.*;
import java.awt.*;
import java.awt.image.ImageObserver;

public class MyFrame extends JFrame {
    MyFrame() {
        //FRAME
        this.setTitle("Title goes here");                       // title of frame
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);    // close on exit
        this.setResizable(true);                               // change size = false
        this.setSize(420, 420);                    // size

        ImageIcon icon = new ImageIcon("sevenStudio.png");              // icon
        this.setIconImage(icon.getImage());                                     // get icon
        this.getContentPane().setBackground(new Color(123, 50, 250));  // set color

        JLabel label = new JLabel();                    //label
        ImageIcon labelIcon = new ImageIcon("sevenStudio.png");
        label.setText("This is Label!");
        label.setIcon(labelIcon);
        label.setHorizontalTextPosition(JLabel.CENTER);
        label.setVerticalTextPosition(JLabel.BOTTOM);
                                            // LEFT, RIGHT, CENTER, BOTTOM, TOP wzgledem zdjecia
        this.add(label);
        this.setVisible(true);                   // visibility
    }
}
