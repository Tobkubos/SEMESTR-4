import javax.swing.*;
import javax.swing.border.EmptyBorder;
import javax.swing.border.LineBorder;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class MyFrame extends JFrame {
    MyFrame() {
        //FRAME
        this.setTitle("Toolbarek");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setResizable(false);
        this.setSize(700, 700);
        this.setVisible(true);

        ImageIcon icon = new ImageIcon("sevenStudio.png");
        this.setIconImage(icon.getImage());

        JPanel mainPanel = new JPanel();
        mainPanel.setLayout(null);  // Ustawiamy na null, aby ręcznie pozycjonować elementy
        mainPanel.setBackground(new Color(123, 50, 250));
        this.add(mainPanel);

        JPanel toolbarPanel = new JPanel();
        toolbarPanel.setBounds(0, 0, this.getWidth(), 55);
        toolbarPanel.setBackground(Color.GREEN);

        JToolBar toolbar = new JToolBar();
        toolbar.setBackground(Color.BLUE);
        toolbar.setBorder(new EmptyBorder(10, 25, 10, 25));
        //toolbar.setBorder(new LineBorder(Color.YELLOW));
        JButton button1 = new JButton("Button 1");
        JButton button2 = new JButton("Button 2");
        JButton button3 = new JButton("Button 3");

        ImageIcon icon1 = new ImageIcon("sevenStudio.png");
        Image image = icon1.getImage().getScaledInstance(30, 30, Image.SCALE_SMOOTH);
        ImageIcon scaledIcon = new ImageIcon(image);
        button1.setIcon(scaledIcon);
        button1.setFont(new Font("Arial", Font.BOLD, 14));
        button1.setBackground(Color.BLACK);
        button1.setBorder(new LineBorder(Color.RED));
        button1.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseEntered(MouseEvent e) {
                button1.setBackground(Color.YELLOW); // Ustawiamy kolor tła po najechaniu myszą
            }

            @Override
            public void mouseExited(MouseEvent e) {
                button1.setBackground(null); // Przywracamy domyślny kolor tła po opuszczeniu myszą
            }
        });
        button1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // Zmieniamy kolor tła przycisku na czerwony po kliknięciu
                mainPanel.setBackground(Color.RED);
            }
        });

        toolbar.add(button1);
        toolbar.add(button2);
        toolbar.add(button3);
        toolbarPanel.add(toolbar);
        mainPanel.add(toolbarPanel);
    }
}