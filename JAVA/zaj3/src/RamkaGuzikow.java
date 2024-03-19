import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class RamkaGuzikow extends JFrame {

    private JPanel panelGuzikow;

    public RamkaGuzikow(){
        JButton zielony = new JButton("zielony", new ImageIcon("arrow.png"));
        JButton zolty = new JButton( "zolty");
        JButton rozowy = new JButton("rozowy");

        Dimension currentSize1 = rozowy.getPreferredSize();
        Dimension currentSize2 = zolty.getPreferredSize();
        Dimension currentSize3 = zielony.getPreferredSize();
        rozowy.setPreferredSize(new Dimension(currentSize1.width * 2, currentSize1.height * 2));
        zolty.setPreferredSize(new Dimension(currentSize2.width, currentSize2.height * 5));
        zielony.setPreferredSize(new Dimension(currentSize3.width * 5, currentSize3.height*5));

        panelGuzikow = new JPanel();


        UtworzKolor zieloneTlo = new UtworzKolor(Color.GREEN);
        UtworzKolor zolteTlo   = new UtworzKolor(Color.YELLOW);
        UtworzKolor rozoweTlo  = new UtworzKolor(Color.PINK);

        zielony.addActionListener(zieloneTlo);
        zolty.addActionListener(zolteTlo);
        rozowy.addActionListener(rozoweTlo);

        zielony.setToolTipText("Zielony");
        zolty.setToolTipText("Zolty");
        rozowy.setToolTipText("Rozowy");

        zielony.setBackground(Color.CYAN);
        zolty.setBackground(Color.MAGENTA);
        rozowy.setBackground(Color.ORANGE);

        panelGuzikow.add(zielony);
        panelGuzikow.add(zolty);
        panelGuzikow.add(rozowy);

        add(panelGuzikow);
    }


    private class UtworzKolor implements ActionListener {

        private Color kolorTla;

        public UtworzKolor(Color c){
            kolorTla = c;
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            panelGuzikow.setBackground(kolorTla);
        }
    }
}

