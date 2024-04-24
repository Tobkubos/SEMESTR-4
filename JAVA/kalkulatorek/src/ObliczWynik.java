import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class ObliczWynik implements ActionListener {
    private MyFrame frame;
    float wynik = 0;

    public ObliczWynik(MyFrame frame) {
        this.frame = frame;
    }
    @Override
    public void actionPerformed(ActionEvent e) {

        System.out.println(frame.firstNUmber);
        System.out.println(frame.operator);
        System.out.println(frame.SecondNumber);

        float fn = Float.parseFloat(frame.firstNUmber);
        float cn = Float.parseFloat(frame.SecondNumber);
        switch (frame.operator) {
            case "+":
                wynik = fn + cn;
                frame.Equasion.setText(frame.firstNUmber + frame.operator + frame.SecondNumber + "=" + wynik);
                break;
            case "-":
                wynik = fn - cn;
                frame.Equasion.setText(frame.firstNUmber + frame.operator + frame.SecondNumber + "=" + wynik);
                break;
            case "*":
                wynik = fn * cn;
                frame.Equasion.setText(frame.firstNUmber + frame.operator + frame.SecondNumber + "=" + wynik);
                break;
            case "/":
                wynik = fn / cn;
                frame.Equasion.setText(frame.firstNUmber + frame.operator + frame.SecondNumber + "=" + wynik);
                break;

        }
    }
}