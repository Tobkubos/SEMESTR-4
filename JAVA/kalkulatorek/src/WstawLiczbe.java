import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class WstawLiczbe implements ActionListener {
    private MyFrame frame;
    private String liczba;

    public WstawLiczbe(MyFrame frame, String cyfra) {
        this.frame = frame;
        this.liczba = cyfra;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        Appender(liczba);
    }

    public void Appender(String str){
        if(frame.first) {
            frame.Equasion.append(str);
        }
        else{
            frame.Equasion.append(str);
            frame.SecondNumber+=str;
        }
    }
}