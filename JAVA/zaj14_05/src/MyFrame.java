import javax.swing.*;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import java.awt.*;
import java.util.Dictionary;
import java.util.Hashtable;

public class MyFrame extends JFrame {
    public String one = "0";
    public String two = "0";
    public String three ="0";
    MyFrame(){
        this.setSize(700,700);
        this.setTitle("Jslider");
        this.setLayout(new GridLayout(4,1));

        JLabel val = new JLabel();
        val.setFont(new Font("Arial", Font.PLAIN, 70));
        this.add(val);

        JSlider js = new JSlider();
        js.setValue(500);
        js.setMinimum(100);
        js.setMaximum(1000);
        js.setMajorTickSpacing(100);
        js.setPaintTrack(true);
        js.setPaintTicks(true);
        js.setPaintLabels(true);

        js.addChangeListener(new ChangeListener() {
            @Override
            public void stateChanged(ChangeEvent e) {
                JSlider source = (JSlider) e.getSource();
                one = (String.valueOf(source.getValue()));
                val.setText( one +" "+two+" "+three);
            }
        });

        this.add(js);

        JSlider js2 = new JSlider();
        js2.setMinimum(0);
        js2.setMaximum(5);
        Dictionary<Integer,Component> labelTable = new Hashtable<>();
        labelTable.put(0, new JLabel("A"));
        labelTable.put(1, new JLabel("B"));
        labelTable.put(2, new JLabel("C"));
        labelTable.put(3, new JLabel("D"));
        labelTable.put(4, new JLabel("E"));
        labelTable.put(5, new JLabel("F"));
        js2.setLabelTable(labelTable);
        js2.setPaintTrack(true);
        js2.setPaintTicks(true);
        js2.setPaintLabels(true);
        js2.setValue(3);

        js2.addChangeListener(new ChangeListener() {
            @Override
            public void stateChanged(ChangeEvent e) {
                JSlider source = (JSlider) e.getSource();
                int value = source.getValue();
                two = (String) ((JLabel) labelTable.get(value)).getText();
                val.setText(one + " " + two+" "+three);
            }
        });

        this.add(js2);

        JSpinner jsp = new JSpinner(new SpinnerNumberModel(1,1,31,1));

        jsp.addChangeListener(new ChangeListener() {
            @Override
            public void stateChanged(ChangeEvent e) {
                JSpinner source = (JSpinner) e.getSource();
                int value = (int) source.getValue();
                three = String.valueOf(value);
                val.setText(one + " " + two+" "+three);
            }
        });

        this.add(jsp);




        this.setVisible(true);
    }

}
