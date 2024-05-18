import javax.imageio.ImageIO;
import javax.swing.*;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import javax.tools.Tool;
import java.awt.*;
import java.awt.event.*;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class PaintPanel extends JFrame {
    ArrayList<PaintPoint> paintPoints = new ArrayList<>();
    private int currentSize = 10;
    private int currentShape = 0;
    private boolean isDrawing = false;
    private boolean isSpraying = false;
    private BufferedImage image = null;

    //private JLabel BrushTypeLabel, BrushSizeLabel, BrushColorLabel;
    ImageIcon brushIcon = new ImageIcon("brush.png");
    ImageIcon SprayIcon = new ImageIcon("spray.png");
    ImageIcon LoadImageIcon = new ImageIcon("image.png");
    ImageIcon CircleShapeIcon = new ImageIcon("circle.png");
    ImageIcon CircleFillShapeIcon = new ImageIcon("circle_fill.png");
    ImageIcon SquareShapeIcon = new ImageIcon("square.png");
    ImageIcon SquareFillShapeIcon = new ImageIcon("square_fill.png");
    Font ProgramFont = new Font("Sans Serif", Font.PLAIN, 20);
    class PaintPoint{
        private final int x;
        private final int y;
        private final int size;
        private final int shape;

        public PaintPoint(int x, int y, int size, int shape) {
            this.x = x;
            this.y = y;
            this.size = size;
            this.shape = shape;
        }

        public void draw(Graphics2D g2d) {
            if(shape == 0){
            g2d.setColor(Color.BLUE);
            g2d.drawOval(x - size / 2, y - size / 2, size, size);
            }
            if(shape == 1){
                g2d.setColor(Color.RED);
                g2d.fillOval(x - size / 2, y - size / 2, size, size);
            }
            if(shape == 2){
                g2d.setColor(Color.YELLOW);
                g2d.drawRect(x - size / 2, y - size / 2, size, size);
            }
            if(shape == 3){
                g2d.setColor(Color.BLACK);
                g2d.fillRect(x - size / 2, y - size / 2, size, size);
            }
        }

    }
    PaintPanel(int Dimx, int Dimy) {
        setResizable(true);
        setSize(Dimx, Dimy);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());
        add(new DrawingPanel(), BorderLayout.CENTER);
        add(new Toolbar(), BorderLayout.SOUTH);
        //new ActualBrushInfo();
        add(new NorthPanel(), BorderLayout.NORTH);
        setVisible(true);
    }

    //INFORMACJA O BRUSH
    /*
    class ActualBrushInfo extends JFrame {
        ActualBrushInfo() {
            setSize(200, 200);
            setResizable(false);
            setAlwaysOnTop(true);
            setLocationRelativeTo(this);
            setLocation(900, 100);
            setVisible(true);

            JPanel info = new JPanel(new GridLayout(4,1));
            add(info);

            BrushTypeLabel = new JLabel("type: brush", brushIcon, JLabel.LEFT);
            BrushTypeLabel.setFont(ProgramFont);
            info.add(BrushTypeLabel);

            BrushSizeLabel = new JLabel("size: 1");
            BrushSizeLabel.setFont(ProgramFont);
            info.add(BrushSizeLabel);

            BrushColorLabel = new JLabel("color: ");
            BrushColorLabel.setFont(ProgramFont);
            info.add(BrushColorLabel);
        }
    }
     */
    class Toolbar extends JToolBar{
        Toolbar(){
            setLayout(new GridLayout(1,5));

            JPanel jp1 = new JPanel(new GridLayout(2,1));
            JLabel jl1 = new JLabel("size");
            jl1.setHorizontalAlignment(SwingConstants.CENTER);
            SpinnerNumberModel spinnerModel = new SpinnerNumberModel(1, 1, 100, 1);
            JSpinner spinner = new JSpinner(spinnerModel);

            spinner.setFont(ProgramFont);
            spinner.addChangeListener(e -> {
                currentSize = (Integer) spinner.getValue();
                }
            );
            jp1.add(jl1);
            jp1.add(spinner);
            add(jp1);

            JButton loadButton = new JButton(LoadImageIcon);
            loadButton.setFont(ProgramFont);
            loadButton.addActionListener(e -> loadImage());
            add(loadButton);

            ButtonGroup bg = new ButtonGroup();

            JPanel jp3 = new JPanel(new GridLayout(2,1));
            JButton JRbrush = new JButton(brushIcon);
            JRbrush.addActionListener(new ButtonActionListener(false));

            JButton JRspray = new JButton(SprayIcon);
            JRspray.addActionListener(new ButtonActionListener(true));

            JRbrush.setSelected(true);
            JRspray.setSelected(false);

            bg.add(JRspray);
            bg.add(JRbrush);
            jp3.add(JRspray);
            jp3.add(JRbrush);
            add(jp3);


            JPanel jp4 = new JPanel(new GridLayout(3,3));
            ButtonGroup ShapeGroup = new ButtonGroup();
            CreateShapeButton(CircleShapeIcon,      0, ShapeGroup, jp4);
            CreateShapeButton(CircleFillShapeIcon,  1, ShapeGroup, jp4);
            CreateShapeButton(SquareShapeIcon,      2, ShapeGroup, jp4);
            CreateShapeButton(SquareFillShapeIcon,  3, ShapeGroup, jp4);
            add(jp4);

            JButton ClearLastPoint = new JButton("undo");
            ClearLastPoint.addActionListener(new ActionListener() {
                @Override

                public void actionPerformed(ActionEvent e) {
                    if(!paintPoints.isEmpty()) {
                        paintPoints.removeLast();
                        repaint();
                    }               }
            });
            add(ClearLastPoint);

            JButton ClearAll = new JButton("Clear");
            ClearAll.addActionListener(new ActionListener() {
                @Override

                public void actionPerformed(ActionEvent e) {
                    paintPoints.clear();
                    repaint();
                }
            });
            add(ClearAll);
        }

        void CreateShapeButton(ImageIcon ShapeIcon ,int sp, ButtonGroup bg, JPanel jp){
            JButton Shape = new JButton(ShapeIcon);
            Shape.addActionListener(new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    currentShape = sp;
                }
            });
            bg.add(Shape);
            jp.add(Shape);
        }

        class ButtonActionListener implements ActionListener {
            private final boolean state;
            public ButtonActionListener(boolean s) {
                this.state = s;
            }
            @Override
            public void actionPerformed(ActionEvent e) {
                    isSpraying = this.state;
            }
        }
        private void loadImage() {
            JFileChooser fileChooser = new JFileChooser();
            int returnValue = fileChooser.showOpenDialog(null);
            if (returnValue == JFileChooser.APPROVE_OPTION) {
                File selectedFile = fileChooser.getSelectedFile();
                try {
                    image = ImageIO.read(selectedFile);
                    repaint();
                    JFrame frame = (JFrame) SwingUtilities.getWindowAncestor(this);
                    frame.setSize(frame.getWidth()+1, frame.getHeight());

                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }
    class DrawingPanel extends JPanel implements MouseListener, MouseMotionListener, KeyListener, MouseWheelListener  {

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
            PaintPoint paintPoint = new PaintPoint(x, y, currentSize, currentShape);
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
            for (PaintPoint paintPoint : paintPoints) {
                paintPoint.draw(g2d);
            }
            repaint();
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


        @Override
        public void keyTyped(KeyEvent e) {
        }

        @Override
        public void keyPressed(KeyEvent e) {

        }

        @Override
        public void keyReleased(KeyEvent e) {

        }

        @Override
        public void mouseWheelMoved(MouseWheelEvent e) {

        }
    }
}
