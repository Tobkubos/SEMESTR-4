import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MyFrame extends JFrame {
    private JComboBox<String> cb;
    private JLabel l;
    MyFrame(){
        //frame
        this.setVisible(true);
        this.setSize(400,400);
        this.setTitle("ComboBoxTest");
        l = new JLabel("Testowy Tekst");
        this.add(l, BorderLayout.CENTER);

        //Combo box
        cb = new JComboBox<>();
        cb.addItem("Serif");
        cb.addItem("SansSerif");
        cb.addItem("Monospaced");

        //listener
        ActionListener sluchacz = event -> {
            ChangeFont(cb.getItemAt(cb.getSelectedIndex()));
        };
        cb.addActionListener(sluchacz);
        this.add(cb, BorderLayout.NORTH);

        //radio buttons
        ButtonGroup bg1 = new ButtonGroup();
        JRadioButton jb1 = new JRadioButton("Small", null, false);
        JRadioButton jb2 = new JRadioButton("Medium", null, false);
        JRadioButton jb3 = new JRadioButton("Large", null, false);
        JRadioButton jb4 = new JRadioButton("XLarge", null, false);
        JRadioButton jb5 = new JRadioButton("XXLarge", null, false);

        JPanel jp2 = new JPanel();
        jp2.setLayout(new GridLayout(1,5));
        this.add(jp2, BorderLayout.SOUTH);

        jp2.add(jb1);
        jp2.add(jb2);
        jp2.add(jb3);
        jp2.add(jb4);
        jp2.add(jb5);

        bg1.add(jb1);
        bg1.add(jb2);
        bg1.add(jb3);
        bg1.add(jb4);
        bg1.add(jb5);
    }

    public void ChangeFont(String FontName){
        l.setFont(new Font(FontName, Font.PLAIN, 40));
    }
}
