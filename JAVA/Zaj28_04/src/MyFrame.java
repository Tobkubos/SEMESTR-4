import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MyFrame extends JFrame {
    private JComboBox<String> cb;
    public JPanel jp2;
    public JPanel jp3;
    public ButtonGroup bg1;
    private JLabel l;
    int FontStyle = Font.PLAIN;
    int FontSize = 30;
    Font font;
    String FontName = "Arial";

    MyFrame(){
        //frame
        this.setSize(400,600);
        this.setTitle("ComboBoxTest");
        l = new JLabel("Tekst");

        font = new Font(FontName,FontStyle,FontSize);
        l.setFont(font);
        l.setHorizontalAlignment(SwingConstants.CENTER);
        l.setVerticalAlignment(SwingConstants.CENTER);

        //Combo box
        cb = new JComboBox<>();
        cb.setPreferredSize(new Dimension(200, 30));
        ComboboxAdder("Monospaced");
        ComboboxAdder("Serif");
        ComboboxAdder("SansSerif");

        //radio buttons
        bg1 = new ButtonGroup();
        jp2 = new JPanel();
        jp2.setLayout(new GridLayout(1,5));

        RadioButtonCreator("small", 10);
        RadioButtonCreator("medium", 25);
        RadioButtonCreator("large", 50);


        //checkboxes
        jp3 = new JPanel();
        CheckBoxCreator("Bold", Font.BOLD);
        CheckBoxCreator("Plain", Font.PLAIN);
        CheckBoxCreator("Italic", Font.ITALIC);

        //ustawienie
        JPanel jp1 = new JPanel();
        jp1.setLayout(new GridLayout(2,1));

        this.add(cb, BorderLayout.NORTH);
        this.add(l, BorderLayout.CENTER);
        jp1.add(jp2);
        jp1.add(jp3);
        this.add(jp1, BorderLayout.SOUTH);
        this.setVisible(true);
    }

    public void ComboboxAdder(String name){
        cb.addItem(name);
        //listener
        ActionListener sluchacz = event -> {
            FontName = cb.getItemAt(cb.getSelectedIndex());
            updateFont();
        };
        cb.addActionListener(sluchacz);
    }

    public void RadioButtonCreator(String name, int size){
            JRadioButton jrb = new JRadioButton(name,null,false);
            ActionListener sluchacz = event -> {
                ChangeSize(size);
            };
        jrb.addActionListener(sluchacz);
        jp2.add(jrb);
        bg1.add(jrb);
    }
    public void CheckBoxCreator(String name, int fs){
        JCheckBox jcb = new JCheckBox(name, null, false);
        ActionListener sluchacz = event -> {
            JCheckBox clickedCheckbox = (JCheckBox) event.getSource();
            if (clickedCheckbox.isSelected()) {
                for (Component component : jp3.getComponents()) {
                    if (component instanceof JCheckBox && component != clickedCheckbox) {
                        ((JCheckBox) component).setSelected(false);
                    }
                }
                ChangeStyle(fs);
            }
        };
        jcb.addActionListener(sluchacz);
        jp3.add(jcb);
    }

    public void ChangeStyle(int style){
        FontStyle = style;
        updateFont();
    }
    public void ChangeSize(int size){
        FontSize = size;
        updateFont();
    }
    public void updateFont() {
        font = new Font(FontName, FontStyle, FontSize);
        l.setFont(font);
    }
}
