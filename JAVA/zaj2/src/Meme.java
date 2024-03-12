import javax.swing.*;
import java.awt.*;

public class Meme extends JFrame {
    public static void main(String[] args) {
        EventQueue.invokeLater(new Runnable() {
            public void run(){
            Meme frame = new Meme();
            frame.setTitle("MEMO-INATOR");
            frame.setVisible(true);
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame.add(new FillArea2());
            frame.pack();
        }});
    }
}

class FillArea2 extends JComponent {
    private static final int width = 500;
    private static final int height = 500;
    private ImageIcon icon = new ImageIcon("polskaGurom.jpg");

    public void paintComponent(Graphics g) {

        int CurrentHeight = this.getHeight();
        int CurrentWidth = this.getWidth();

        for(int i = 0; i < CurrentHeight; i+= icon.getIconHeight()) {
            for(int j = 0; j<CurrentWidth; j+= icon.getIconWidth()){
            g.drawImage(icon.getImage(), j, i, null);
            }
        }
    }

    public Dimension getPreferredSize() {
        return new Dimension(width, height);
    }
}