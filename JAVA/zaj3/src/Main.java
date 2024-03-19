import javax.swing.*;
import java.awt.*;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        EventQueue.invokeLater(new Runnable() {
            @Override
            public void run() {
                JFrame ramka = new RamkaGuzikow();
                ramka.setTitle("GUZIKI");
                ramka.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                ramka.setVisible(true);
                ramka.setSize(600,400);
            }
        });
    }
}