import javax.imageio.ImageIO;
import javax.swing.*;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import javax.tools.Tool;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class PaintPanel extends JFrame {
    ArrayList<PaintPoint> paintPoints = new ArrayList<>();
    private int currentSize = 10;
    private boolean isDrawing = false;

    private boolean isSpraying = false;
    private BufferedImage image = null;

    private JLabel LabelSize;
    class PaintPoint{
        private int x;
        private int y;
        private int size;

        public PaintPoint(int x, int y, int size) {
            this.x = x;
            this.y = y;
            this.size = size;
        }

        public void draw(Graphics2D g2d) {
            g2d.setColor(Color.BLUE);
            g2d.fillOval(x - size / 2, y - size / 2, size, size);
        }
    }
    PaintPanel(int Dimx, int Dimy) {
        setResizable(true);
        setSize(Dimx, Dimy);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());
        add(new DrawingPanel(), BorderLayout.CENTER);
        add(new Toolbar(), BorderLayout.NORTH);
        new ActualBrushInfo();

        setVisible(true);
    }

    class ActualBrushInfo extends JFrame {
        ActualBrushInfo() {
            setSize(200, 200);
            setResizable(false);
            setAlwaysOnTop(true);
            setLocationRelativeTo(this);
            setLocation(900, 100); // Ustawienie pozycji okna ActualBrushInfo
            setVisible(true);

            JPanel info = new JPanel();
            add(info,BorderLayout.CENTER);
        }
    }
    class Toolbar extends JToolBar{
        Toolbar(){
            SpinnerNumberModel spinnerModel = new SpinnerNumberModel(1, 1, 100, 1);
            JSpinner spinner = new JSpinner(spinnerModel);
            spinner.addChangeListener(e -> currentSize = (Integer) spinner.getValue());
            add(spinner);

            JButton loadButton = new JButton("Load Image");
            loadButton.addActionListener(e -> loadImage());
            add(loadButton);

            ButtonGroup bg = new ButtonGroup();
            JRadioButton JRbrush = new JRadioButton("brush");
            JRadioButton JRspray = new JRadioButton("spray");
            JRspray.addActionListener(e -> isSpraying = JRspray.isSelected());
            JRspray.setSelected(false);
            JRbrush.addActionListener(e -> isSpraying = JRspray.isSelected());
            JRbrush.setSelected(true);
            bg.add(JRspray);
            bg.add(JRbrush);
            add(JRspray);
            add(JRbrush);
        }

        private void loadImage() {
            JFileChooser fileChooser = new JFileChooser();
            int returnValue = fileChooser.showOpenDialog(null);
            if (returnValue == JFileChooser.APPROVE_OPTION) {
                File selectedFile = fileChooser.getSelectedFile();
                try {
                    image = ImageIO.read(selectedFile);
                    repaint();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }
    class DrawingPanel extends JPanel implements MouseListener, MouseMotionListener {

        DrawingPanel(){
            setBackground(Color.GREEN);
            addMouseListener(this);
            addMouseMotionListener(this);
        }
        private void addPoint(MouseEvent e) {
            int x;
            int y;
            Random random = new Random();
            if(isSpraying) {
                int SpraySize = currentSize*5;
                x = e.getX() +random.nextInt(SpraySize) - SpraySize/2;
                y = e.getY()+ random.nextInt(SpraySize) - SpraySize/2;
            }
            else{
                x = e.getX();
                y = e.getY();
            }
            PaintPoint paintPoint = new PaintPoint(x, y, currentSize);
            paintPoints.add(paintPoint);
            repaint();
        }

        @Override
        protected void paintComponent(Graphics g) {
            super.paintComponent(g);
            Graphics2D g2d = (Graphics2D) g;
            g2d.setColor(new Color(120,100,200));
            if (image != null) {
                g2d.drawImage(image, 0, 0, getWidth(), getHeight(), this);
            }
            draw(g2d);
        }

        private void draw(Graphics2D g2d) {

                for (PaintPoint paintPoint : paintPoints) {
                    paintPoint.draw(g2d);
                }
        }

        @Override
        public void mouseClicked(MouseEvent e) {
            addPoint(e);
        }

        @Override
        public void mousePressed(MouseEvent e) {
            isDrawing = true;
            addPoint(e);
        }
        @Override
        public void mouseDragged(MouseEvent e) {
            if (isDrawing) {
                addPoint(e);
            }
        }
        public void mouseMoved(MouseEvent e) {

        }
        @Override
        public void mouseReleased(MouseEvent e) {
            isDrawing = false;
        }

        @Override
        public void mouseEntered(MouseEvent e) {

        }

        @Override
        public void mouseExited(MouseEvent e) {

        }
    }
}
