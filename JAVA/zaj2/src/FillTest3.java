import javax.swing.*;
import java.awt.*;
import java.awt.geom.Ellipse2D;
import java.awt.geom.Rectangle2D;

public class FillTest3 extends JFrame {
    public static void main(String[] args){

        EventQueue.invokeLater(new Runnable() {
            public void run() {

                FillTest frame = new FillTest();

                frame.setTitle("ZAJECIA 2");
                frame.setVisible(true);

                frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

                frame.add(new FillArea3());
                frame.pack();
            }
        });

    }
}
class FillArea3 extends JComponent{
    private static final int width = 400;
    private static final int height = 550;

    public void paintComponent(Graphics g){
        Graphics2D g2 = (Graphics2D) g;

        double X = 90;
        double Y = 90;
        double width = 250;
        double height = 250;

        Rectangle2D rect = new Rectangle2D.Double(X,Y,width, height);
        g2.setColor(Color.BLACK);
        g2.setStroke(new BasicStroke(5));
        g2.draw(rect);

        Ellipse2D ellipse = new Ellipse2D.Double();
        ellipse.setFrame(rect);
        g2.setColor(Color.BLACK);
        g2.setStroke(new BasicStroke(5));
        g2.draw(ellipse);

        Rectangle2D rect2 = new Rectangle2D.Double(X,Y,width/2, height/2);
        g2.setColor(Color.BLACK);
        g2.setStroke(new BasicStroke(5));
        g2.rotate(Math.toRadians(45));
        g2.draw(rect2);
    }

    public Dimension getPreferredSize(){
        return new Dimension(width,height);
    }
}