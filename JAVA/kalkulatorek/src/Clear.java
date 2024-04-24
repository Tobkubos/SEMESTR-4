import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Clear implements ActionListener {
    private MyFrame frame;
    public Clear(MyFrame frame){
        this.frame = frame;
    }
    @Override
    public void actionPerformed(ActionEvent e) {
        frame.firstNUmber = "";
        frame.SecondNumber = "";
        frame.first = true;
        frame.operator = "";
        frame.Equasion.setText("");
    }
}
