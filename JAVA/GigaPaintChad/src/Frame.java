import javax.swing.*;
import javax.swing.border.EmptyBorder;
import javax.swing.border.LineBorder;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.Random;

public class Frame extends JFrame {
    Frame() {
        //FRAME
        this.setTitle("Toolbarek");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setResizable(false);
        this.setSize(700, 700);


        ImageIcon AppIcon = new ImageIcon("sevenStudio.png");
        this.setIconImage(AppIcon.getImage());

        JPanel ColorPanel = new JPanel();
        JToolBar ColorToolbar = new JToolBar();

        GridLayout ColorLayout = new GridLayout(3,10,3,3);
        ColorToolbar.setLayout(ColorLayout);

        ColorButton[] ColorButtons = new ColorButton[20];
        ColorButton[] ColorButtonsRecent = new ColorButton[10];
        Color[] colors = {
                new Color(0x000000), new Color(0x7f7f7f), new Color(0xc3c3c3), new Color(0xffffff),
                new Color(0x880015), new Color(0xed1c24), new Color(0xb97a57), new Color(0xff7f27),
                new Color(0xffc90e), new Color(0xfff200), new Color(0xefe4b0), new Color(0xb5e61d),
                new Color(0x22b14c), new Color(0x99d9ea), new Color(0x7092be), new Color(0x00a2e8),
                new Color(0x3f48cc), new Color(0xa349a4), new Color(0xffaec9), new Color(0xc8bfe7)
        };

        for (int i = 0; i < ColorButtons.length; i++) {
            ColorButtons[i] = new ColorButton(colors[i]);
            ColorToolbar.add(ColorButtons[i]);
        }

        for (int i = 0; i < ColorButtonsRecent.length; i++) {
            ColorButtonsRecent[i] = new ColorButton(Color.WHITE);
            ColorToolbar.add(ColorButtonsRecent[i]);
        }

        JColorChooser JCC = new JColorChooser();
        ColorPanel.add(JCC);


        ColorPanel.add(ColorToolbar);
        this.add(ColorPanel);
        this.setVisible(true);
    }
}