import javax.swing.*;
import javax.swing.border.Border;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MyFrame extends JFrame implements ActionListener{
    MyFrame() {
        //FRAME
        this.setTitle("Title goes here");                       // title of frame
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);    // close on exit
        this.setResizable(true);                               // change size = false
        this.setSize(700, 700);                    // size

        ImageIcon icon = new ImageIcon("sevenStudio.png");              // icon
        this.setIconImage(icon.getImage());                                     // get icon
        this.getContentPane().setBackground(new Color(123, 50, 250));  // set color
        this.setLayout(null);           //będziemy ustawiać ręcznie wielkości paneli

        // -----------------------------------------------------------------------
        Border border = BorderFactory.createLineBorder(Color.GREEN,3);
        // -----------------------------------------------------------------------
        JLabel label = new JLabel();                    //label
        ImageIcon labelIcon = new ImageIcon("sevenStudio.png");
        label.setText("This is Label!");
        label.setIcon(labelIcon);
        label.setHorizontalTextPosition(JLabel.CENTER);
        label.setVerticalTextPosition(JLabel.BOTTOM);               // LEFT, RIGHT, CENTER, BOTTOM, TOP wzgledem zdjecia
        label.setHorizontalAlignment(JLabel.CENTER);
        label.setVerticalAlignment(JLabel.CENTER);
        label.setForeground(Color.RED);                             //font color
        label.setFont(new Font("Arial", Font.BOLD, 48)); //font
        label.setIconTextGap(-50);                                  //margin from image
        label.setBackground(Color.BLACK);                           //background
        label.setOpaque(true);                                      //needed for bg color
        label.setBorder(border);                                    //border
        label.setBounds(0,0,550,550);          // wielkosc okna
        // ------------------------------------------------------------------------
        JPanel redPanel = new JPanel();
        redPanel.setBackground(Color.RED);
        redPanel.setBounds(0,0,250,250);

        JPanel bluePanel = new JPanel();
        bluePanel.setBackground(Color.BLUE);
        bluePanel.setBounds(250,0,250,250);

        JPanel greenPanel = new JPanel();
        greenPanel.setBackground(Color.green);
        greenPanel.setBounds(0,250,500,250);

        ImageIcon icon2 = new ImageIcon("toilet.png");

        JLabel label2 = new JLabel();
        label2.setText("GIGA LABEL");
        label2.setIcon(icon2);
        greenPanel.add(label2);
        // ------------------------------------------------------------------------
        JButton button = new JButton();
        button.addActionListener(this);
        button.setBounds(0,0,100,100);
        button.setIcon(icon);

        // ------------------------------------------------------------------------
        this.setVisible(true);                   // visibility
        //this.pack();
        //--
        //this.add(label);
        //--
        //this.add(redPanel);
        //this.add(greenPanel);
        //this.add(bluePanel);
        //--
        this.add(button);
        //--
    }

    @Override
    public void actionPerformed(ActionEvent e){
        System.out.println("KLIKEN");
        JButton button = (JButton) e.getSource(); // Pobranie źródła zdarzenia
        button.setEnabled(false); // Wyłączenie przycisku
    }
}
