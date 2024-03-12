import javax.swing.*;
import java.awt.*;
import java.awt.geom.Ellipse2D;
import java.awt.geom.Rectangle2D;

public class FillTest extends JFrame {
    public static void main(String[] args){

        EventQueue.invokeLater(new Runnable() {
            public void run() {

                FillTest frame = new FillTest();

                frame.setTitle("ZAJECIA 2");
                frame.setVisible(true);

                frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

                frame.add(new FillArea());
                frame.pack();
            }
        });

    }
}
class FillArea extends JComponent{
    private static final int width = 400;
    private static final int height = 550;

    public void paintComponent(Graphics g){
        Graphics2D g2 = (Graphics2D) g;

        double X = 90;
        double Y = 90;
        double width = 200;
        double height = 150;

        Rectangle2D rect = new Rectangle2D.Double(X,Y,width, height);
        g2.setColor(Color.BLACK);
        g2.draw(rect);
        g2.setColor(Color.BLUE);
        g2.fill(rect);


        Ellipse2D ellipse = new Ellipse2D.Double();
        ellipse.setFrame(rect);
        g2.setColor(Color.CYAN);
        g2.fill(ellipse);


    }

    public Dimension getPreferredSize(){
        return new Dimension(width,height);
    }
}