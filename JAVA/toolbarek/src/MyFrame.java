import javax.swing.*;
import javax.swing.border.EmptyBorder;
import javax.swing.border.LineBorder;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.Random;

public class MyFrame extends JFrame {
    MyFrame() {
        //FRAME
        this.setTitle("Toolbarek");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setResizable(false);
        this.setSize(700, 700);


        ImageIcon icon = new ImageIcon("sevenStudio.png");
        ImageIcon Lebron = new ImageIcon("Lebron.jpg");
        this.setIconImage(icon.getImage());

        JPanel mainPanel = new JPanel();
        mainPanel.setLayout(null);  // Ustawiamy na null, aby ręcznie pozycjonować elementy
        mainPanel.setBackground(new Color(0x45364B));
        this.add(mainPanel);

        JPanel toolbarPanel = new JPanel();
        toolbarPanel.setBounds(0, 0, this.getWidth(), 55);
        toolbarPanel.setBackground(new Color(0x8C93A8));

        JToolBar toolbar = new JToolBar();
        toolbar.setBackground(new Color(0x62466B));
        toolbar.setBorder(new EmptyBorder(10, 25, 10, 25));
        //toolbar.setBorder(new LineBorder(Color.YELLOW));
        CustomButton button1 = new CustomButton("Button 1   ", "sevenStudio.png");
        CustomButton button2 = new CustomButton("Button 1   ", "sevenStudio.png");
        CustomButton button3 = new CustomButton("Button 1   ", "sevenStudio.png");
        button1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // Zmieniamy kolor tła przycisku na czerwony po kliknięciu
                Random rand = new Random();
                int r = rand.nextInt(256);
                int g = rand.nextInt(256);
                int b = rand.nextInt(256);

                mainPanel.setBackground(new Color(r,g,b));
            }
        });

        button2.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // Tworzenie nowego okna dialogowego
                JOptionPane.showMessageDialog(MyFrame.this, "LJ", "LLEEEEBROOOOOOOOOOOON JAMEEEEEEEEEEEEEEES", JOptionPane.INFORMATION_MESSAGE, Lebron);
            }
        });

        button3.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String newButtonText = JOptionPane.showInputDialog(MyFrame.this, "Wprowadź nazwę:");
                if (newButtonText != null && !newButtonText.isEmpty()) {
                    button3.setText(newButtonText);
                }
            }
        });

        toolbar.add(button1);
        toolbar.addSeparator(new Dimension(30,30));
        toolbar.add(button2);
        toolbar.addSeparator(new Dimension(30,30));
        toolbar.add(button3);
        toolbarPanel.add(toolbar);
        mainPanel.add(toolbarPanel);
        this.setVisible(true);
    }
}