import javax.imageio.ImageIO;
import javax.swing.*;
import javax.swing.border.Border;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import javax.tools.Tool;
import java.awt.*;
import java.awt.event.*;
import java.awt.geom.AffineTransform;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class PaintPanel extends JFrame {
    ArrayList<PaintPoint> paintPoints = new ArrayList<>();
    ArrayList<JButton> colorButtons = new ArrayList<>();

    private int StartX, StartY, EndX, EndY;
    private int ShapeW, ShapeH;

    private int currentSize = 10;
    private int currentShape = 0;

    JButton colorPlate;
    private int currentRed = 0;
    private int currentGreen = 0;
    private int currentBlue = 0;
    private Color currentColor;

    private boolean isDrawing = false;
    private boolean isSpraying = false;
    private boolean isRandomRotating = false;
    private boolean isBigShape = false;

    private BufferedImage image = null;
    private DrawingPanel drawingPanel;
    //private JLabel BrushTypeLabel, BrushSizeLabel, BrushColorLabel;
    ImageIcon brushIcon = new ImageIcon("brush.png");
    ImageIcon SprayIcon = new ImageIcon("spray.png");
    ImageIcon LoadImageIcon = new ImageIcon("image.png");
    ImageIcon CircleShapeIcon = new ImageIcon("circle.png");
    ImageIcon CircleFillShapeIcon = new ImageIcon("circle_fill.png");
    ImageIcon SquareShapeIcon = new ImageIcon("square.png");
    ImageIcon SquareFillShapeIcon = new ImageIcon("square_fill.png");
    Font ProgramFont = new Font("Sans Serif", Font.PLAIN, 20);
    class PaintPoint {
        private final int x;
        private final int y;
        private final int size1;
        private final int size2;
        private final int shape;
        private final Color color;
        private final int rotation;

        public PaintPoint(int x, int y, int size1, int size2, int shape, Color color, int rotation) {
            this.x = x;
            this.y = y;
            this.size1 = size1;
            this.size2 = size2;
            this.shape = shape;
            this.color = color;
            this.rotation = rotation;
        }

        public void draw(Graphics2D g2d) {
            AffineTransform old = g2d.getTransform();
            g2d.setColor(color);
            g2d.rotate(Math.toRadians(rotation), x, y);
            switch (shape) {
                case 0 -> g2d.drawOval(x - size1 / 2, y - size2 / 2, size1, size2);
                case 1 -> g2d.fillOval(x - size1 / 2, y - size2 / 2, size1, size2);
                case 2 -> g2d.drawRect(x - size1 / 2, y - size2 / 2, size1, size2);
                case 3 -> g2d.fillRect(x - size1 / 2, y - size2 / 2, size1, size2);
                case 4 -> {
                    int[] xPoints = {x, x - size1 / 2, x + size1 / 2};
                    int[] yPoints = {y - size2 / 2, y + size2 / 2, y + size2 / 2};
                    g2d.drawPolygon(xPoints, yPoints, 3);
                }
            }
            g2d.setTransform(old);
        }
    }
    PaintPanel(int Dimx, int Dimy) {
        setResizable(true);
        setSize(Dimx, Dimy);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        drawingPanel = new DrawingPanel();
        add(drawingPanel, BorderLayout.CENTER);
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

            setPreferredSize(new Dimension(800, 100)); // Szerokość: 400, Wysokość: 50
            setMinimumSize(new Dimension(800, 100));   // Opcjonalnie: minimalny rozmiar
            setMaximumSize(new Dimension(800, 100));

            //SET SIZE
            JPanel jp1 = new JPanel(new BorderLayout());
            JPanel jp1_2 = new JPanel(new BorderLayout());
            JLabel jl1 = new JLabel("size");
            jl1.setHorizontalAlignment(SwingConstants.CENTER);
            jp1.add(jl1, BorderLayout.NORTH);
            SpinnerNumberModel spinnerModel = new SpinnerNumberModel(1, 1, 100, 1);
            JSpinner spinner = new JSpinner(spinnerModel);

            spinner.setFont(ProgramFont);
            spinner.addChangeListener(e -> {
                currentSize = (Integer) spinner.getValue();
                }
            );
            jp1_2.add(spinner);
            jp1.add(jp1_2);
            add(jp1);



            //LOAD IMAGE
            JPanel jp2 = new JPanel(new BorderLayout());
            JLabel jl2 = new JLabel("load image");
            jl2.setHorizontalAlignment(SwingConstants.CENTER);
            jp2.add(jl2, BorderLayout.NORTH);

            JPanel jp2_2 = new JPanel(new BorderLayout());
            JButton loadButton = new JButton(LoadImageIcon);
            loadButton.setFont(ProgramFont);
            loadButton.addActionListener(e -> loadImage());
            jp2_2.add(loadButton);
            jp2.add(jp2_2);
            add(jp2);



            //TOOLS
            JPanel jp3 = new JPanel(new BorderLayout());
            JPanel jp3_2 = new JPanel(new GridLayout(2,1));
            JLabel jl3 = new JLabel("tools");
            jl3.setHorizontalAlignment(SwingConstants.CENTER);

            JToggleButton JRbrush = new JToggleButton(brushIcon);
            JRbrush.addActionListener(new ButtonActionListener(false));

            JToggleButton JRspray = new JToggleButton(SprayIcon);
            JRspray.addActionListener(new ButtonActionListener(true));

            JRbrush.setSelected(true);
            JRspray.setSelected(false);

            ButtonGroup bg = new ButtonGroup();
            bg.add(JRspray);
            bg.add(JRbrush);
            jp3_2.add(JRspray);
            jp3_2.add(JRbrush);
            jp3.add(jl3, BorderLayout.NORTH);
            jp3.add(jp3_2);
            add(jp3);



            //SHAPES
            JPanel jp4 = new JPanel(new BorderLayout());
            JLabel jl4 = new JLabel("Shapes");
            jl4.setHorizontalAlignment(SwingConstants.CENTER);
            jp4.add(jl4, BorderLayout.NORTH);
            JPanel jp4_2 = new JPanel(new GridLayout(3,3));
            ButtonGroup ShapeGroup = new ButtonGroup();
            CreateShapeButton(CircleShapeIcon,      0, ShapeGroup, jp4_2);
            CreateShapeButton(CircleFillShapeIcon,  1, ShapeGroup, jp4_2);
            CreateShapeButton(SquareShapeIcon,      2, ShapeGroup, jp4_2);
            CreateShapeButton(SquareFillShapeIcon,  3, ShapeGroup, jp4_2);
            CreateShapeButton(null,  4, ShapeGroup, jp4_2);

            jp4.add(jp4_2);
            add(jp4);



            //undo redo clear
            JPanel jp5 = new JPanel(new BorderLayout());
            JLabel jl5 = new JLabel("functions");
            jl5.setHorizontalAlignment(SwingConstants.CENTER);
            jp5.add(jl5, BorderLayout.NORTH);
            JPanel jp5_2 = new JPanel(new GridLayout(2,2));

            JButton ClearLastPoint = new JButton("undo");
            ClearLastPoint.addActionListener(new ActionListener() {
                @Override

                public void actionPerformed(ActionEvent e) {
                    if(!paintPoints.isEmpty()) {
                        paintPoints.removeLast();
                        repaint();
                    }
                }
            });
            jp5_2.add(ClearLastPoint);

            JButton ClearAll = new JButton("Clear");
            ClearAll.addActionListener(new ActionListener() {
                @Override

                public void actionPerformed(ActionEvent e) {
                    paintPoints.clear();
                    repaint();
                }
            });
            jp5_2.add(ClearAll);
            jp5.add(jp5_2);
            add(jp5);



            //COLORS
            JLabel jl7_2 = new JLabel("hex");
            jl7_2.setHorizontalAlignment(SwingConstants.CENTER);
            JPanel jp6 = new JPanel(new BorderLayout());
            jp6.setMinimumSize(new Dimension(400,100));
            JLabel jl6 = new JLabel("color");
            jl6.setHorizontalAlignment(SwingConstants.CENTER);
            jp6.add(jl6, BorderLayout.NORTH);
            jl6.setHorizontalAlignment(SwingConstants.CENTER);

            JPanel jp6_2 = new JPanel(new GridLayout(3,1));




            //RED
            //region red
            JPanel jp6_2_1 = new JPanel(new BorderLayout());
            JSlider red = new JSlider();
            JLabel rval = new JLabel("255");
            red.setMaximum(255);
            red.setValue(0);
            red.addChangeListener(new ChangeListener() {
                @Override
                public void stateChanged(ChangeEvent e) {
                    currentRed = red.getValue();
                    UpdateColor();
                    jl7_2.setText(String.format("#%02x%02x%02x", currentRed, currentGreen, currentBlue));
                    rval.setText(String.valueOf(currentRed));
                }
            });
            jp6_2_1.add(red, BorderLayout.CENTER);
            jp6_2_1.add(rval, BorderLayout.EAST);
            jp6_2.add(jp6_2_1);
            //endregion

            //GREEN
            //region green
            JPanel jp6_2_2 = new JPanel(new BorderLayout());
            JSlider green = new JSlider();
            JLabel gval = new JLabel("255");
            green.setMaximum(255);
            green.setValue(0);
            green.addChangeListener(new ChangeListener() {
                @Override
                public void stateChanged(ChangeEvent e) {
                    currentGreen = green.getValue();
                    UpdateColor();
                    jl7_2.setText(String.format("#%02x%02x%02x", currentRed, currentGreen, currentBlue));
                    gval.setText(String.valueOf(currentGreen));
                }
            });
            jp6_2_2.add(green, BorderLayout.CENTER);
            jp6_2_2.add(gval, BorderLayout.EAST);
            jp6_2.add(jp6_2_2);
            //endregion

            //BLUE
            //region blue
            JPanel jp6_2_3 = new JPanel(new BorderLayout());
            JSlider blue = new JSlider();
            JLabel bval = new JLabel("255");
            blue.setMaximum(255);
            blue.setValue(0);
            blue.addChangeListener(new ChangeListener() {
                @Override
                public void stateChanged(ChangeEvent e) {
                    currentBlue = blue.getValue();
                    UpdateColor();
                    jl7_2.setText(String.format("#%02x%02x%02x", currentRed, currentGreen, currentBlue));
                    bval.setText(String.valueOf(currentBlue));
                }
            });
            jp6_2_3.add(blue, BorderLayout.CENTER);
            jp6_2_3.add(bval, BorderLayout.EAST);
            jp6_2.add(jp6_2_3);
            jp6.add(jp6_2);
            add(jp6);
            //endregion

            jl7_2.setText(String.format("#%02x%02x%02x", currentRed, currentGreen, currentBlue));
            rval.setText(String.valueOf(currentRed));
            gval.setText(String.valueOf(currentGreen));
            bval.setText(String.valueOf(currentBlue));



            //COLOR PLATE
            JPanel jp7 = new JPanel(new BorderLayout());
            JLabel jl7_1 = new JLabel(" ");

            colorPlate = new JButton();
            colorPlate.setEnabled(false);
            jp7.add(colorPlate, BorderLayout.CENTER);
            jp7.add(jl7_1, BorderLayout.NORTH);
            jp7.add(jl7_2, BorderLayout.NORTH);
            add(jp7);

            UpdateColor(); //startup color load



            //ADD COLORS
            JPanel jp8 = new JPanel(new BorderLayout());
            JLabel jl8 = new JLabel("table");
            jl8.setHorizontalAlignment(SwingConstants.CENTER);
            jp8.add(jl8, BorderLayout.NORTH);

            JPanel jp8_2 = new JPanel(new BorderLayout());

            JButton AddColor = new JButton("add Color");
            AddColor.addActionListener(new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    for (int i = colorButtons.size() - 1; i > 0; i--) {
                        Color previousColor = colorButtons.get(i - 1).getBackground();
                        colorButtons.get(i).setBackground(previousColor);
                    }
                    colorButtons.getFirst().setBackground(currentColor);
                }
            });
            jp8_2.add(AddColor, BorderLayout.NORTH);

            JPanel jp8_3 = new JPanel(new GridLayout(3,4));


            for (int i = 0; i<12; i++){
                JButton btn = new JButton();
                colorButtons.add(btn);
                btn.setBackground(Color.WHITE);
                btn.addActionListener(new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent e) {
                        Color temp = btn.getBackground();
                        colorPlate.setBackground(temp);
                        red.setValue(temp.getRed());
                        green.setValue(temp.getGreen());
                        blue.setValue(temp.getBlue());
                    }
                });
                jp8_3.add(btn);
            }
            jp8_2.add(jp8_3);
            jp8.add(jp8_2);
            add(jp8);



            //OTHER
            JPanel jp9 = new JPanel(new BorderLayout());
            JLabel jl9 = new JLabel("other");
            jp9.add(jl9, BorderLayout.NORTH);
            jl9.setHorizontalAlignment(SwingConstants.CENTER);

            JPanel jp9_2 = new JPanel(new GridLayout(2,2));
            JButton setBackGround = new JButton("BG");
            setBackGround.addActionListener(new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    drawingPanel.setBackground(currentColor);
                }
            });
            jp9_2.add(setBackGround);


            JToggleButton bigShape = new JToggleButton("big shape");
            JToggleButton randomRot = new JToggleButton("random Rot");
            bigShape.addActionListener(new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    isBigShape = !isBigShape;
                    JRbrush.setEnabled(!JRbrush.isEnabled());
                    JRspray.setEnabled(!JRspray.isEnabled());
                    randomRot.setSelected(false);
                }
            });
            jp9_2.add(bigShape);

            randomRot.addActionListener(new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    isRandomRotating = randomRot.isSelected();
                    isBigShape = false;
                    JRbrush.setEnabled(true);
                    JRspray.setEnabled(true);
                    bigShape.setSelected(false);
                }
            });
            jp9_2.add(randomRot);
            jp9.add(jp9_2);
            add(jp9);
        }
        void UpdateColor(){
            currentColor = new Color(currentRed, currentGreen, currentBlue);
            colorPlate.setBackground(currentColor);
        }
        void CreateShapeButton(ImageIcon ShapeIcon ,int sp, ButtonGroup bg, JPanel jp){
            JToggleButton Shape = new JToggleButton(ShapeIcon);
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
                    isBigShape = false;
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
            setBackground(Color.WHITE);
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

            int rot = 0;
            if(isRandomRotating){
                rot = random.nextInt(360);
            }
            PaintPoint paintPoint = new PaintPoint(x, y, currentSize, currentSize, currentShape ,currentColor, rot);
            paintPoints.add(paintPoint);
            repaint();
        }

        private void addBigPoint(MouseEvent e) {
            PaintPoint paintPoint = new PaintPoint((StartX + EndX) / 2, (StartY + EndY)/2, ShapeW,ShapeH, currentShape ,currentColor, 0);
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
        }

        @Override
        public void mousePressed(MouseEvent e) {
            if(!isBigShape) {
                addPoint(e);
            }
            StartX = e.getX();
            StartY = e.getY();

        }
        @Override
        public void mouseDragged(MouseEvent e) {
            isDrawing = true;
            if(!isBigShape) {
                if (isDrawing) {
                    addPoint(e);
                }
            }
        }
        public void mouseMoved(MouseEvent e) {

        }
        @Override
        public void mouseReleased(MouseEvent e) {
            isDrawing = false;

            if(isBigShape) {
                if (e.getX() > StartX) {
                    ShapeW = e.getX() - StartX;
                } else {
                    ShapeW = StartX - e.getX();
                }

                if (e.getY() > StartY) {
                    ShapeH = e.getY() - StartY;
                } else {
                    ShapeH = StartY - e.getY();
                }

                EndX = e.getX();
                EndY = e.getY();
                addBigPoint(e);
                repaint();
                System.out.println("START X  " + StartX);
                System.out.println("END   X  " + EndX);
                System.out.println("START Y  " + StartY);
                System.out.println("END   Y  " + EndY);
                System.out.println("------------------");
            }
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
