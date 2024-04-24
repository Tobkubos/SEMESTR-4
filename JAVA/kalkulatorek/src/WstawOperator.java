import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class WstawOperator implements ActionListener {
    private MyFrame frame;
    String znak = "";

    public WstawOperator(MyFrame frame, String ch) {
        this.frame = frame;
        znak = ch;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (frame.firstNUmber == "" && znak == "-"){
            frame.firstNUmber+="-";
            frame.Equasion.setText(frame.firstNUmber);
            return;
        }

        frame.firstNUmber = frame.Equasion.getText();
        frame.first = false;
        frame.SecondNumber = "";
        frame.operator = znak;
        frame.Equasion.setText(frame.firstNUmber + frame.operator);

    }
}