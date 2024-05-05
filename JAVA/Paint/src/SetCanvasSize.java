import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.*;
public class SetCanvasSize extends JFrame{
    MyFrame MF = new MyFrame();
    SetCanvasSize(){
    JDialog SetCanvasSize = new JDialog(this, "Setup");
        SetCanvasSize.setLayout(new GridLayout(6,1,5,20));

        SetCanvasSize.add(new JLabel("Canvas Height",JLabel.CENTER));
    JSlider HeightSlider = new JSlider(50, 1000, 100);
        HeightSlider.setPaintTicks(true);
        HeightSlider.setPaintLabels(true);
        SetCanvasSize.add(HeightSlider);
        HeightSlider.setMajorTickSpacing(800);
        HeightSlider.setMinorTickSpacing(100);
        HeightSlider.setSnapToTicks(true);

        SetCanvasSize.add(new JLabel("Canvas Width",JLabel.CENTER));
    JSlider WidthSlider = new JSlider(50, 1800, 100);
        WidthSlider.setPaintTicks(true);
        WidthSlider.setPaintLabels(true);
        SetCanvasSize.add(WidthSlider);
        WidthSlider.setMajorTickSpacing(800);
        WidthSlider.setMinorTickSpacing(100);
        WidthSlider.setSnapToTicks(true);

    JTextField Summary = new JTextField();
        Summary.setEditable(false);
        HeightSlider.addChangeListener(e -> {
        Summary.setText(Integer.toString(WidthSlider.getValue()) + "x"+Integer.toString(HeightSlider.getValue()));
    });
        WidthSlider.addChangeListener(e -> {
        Summary.setText(Integer.toString(WidthSlider.getValue()) + "x"+Integer.toString(HeightSlider.getValue()));
    });
        SetCanvasSize.add(Summary);
    ///


    JButton Start = new JButton("Start");
        SetCanvasSize.add(Start);
        Start.addActionListener(new ActionListener() {
        @Override
        public void actionPerformed(ActionEvent e) {
            MF.setSize(WidthSlider.getValue(), HeightSlider.getValue());
            SetCanvasSize.setVisible(false);
            MF.setVisible(true);
        }
    });

        SetCanvasSize.setSize(300,400);
        SetCanvasSize.setVisible(true);
    ///////////////////
}}
