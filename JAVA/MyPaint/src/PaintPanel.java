
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.awt.geom.AffineTransform;
import java.awt.image.BufferedImage;
import java.util.ArrayList;
import java.util.Random;

public class PaintPanel extends JFrame {
    ArrayList<PaintPoint> paintPoints = new ArrayList<>();
    ArrayList<PaintPoint> RedoPaintPoints = new ArrayList<>();
    ArrayList<JButton> colorButtons = new ArrayList<>();

    private int StartX, StartY, EndX, EndY;
    private int ShapeW, ShapeH;

    private int currentSize = 10;
    private int currentShape = 0;

    JButton colorPlate;
    JTextField tx;
    private int currentRed = 0;
    private int currentGreen = 0;
    private int currentBlue = 0;
    private Color currentColor;
    private boolean isSpraying = false;

    private boolean isGradienting = false;
    private boolean isRandomRotating = false;
    private boolean isBigShape = false;

    public BufferedImage image = null;
    DrawingPanel drawingPanel;
    Font ProgramFont = new Font("Sans Serif", Font.PLAIN, 20);
    static class PaintPoint {
        private final int x;
        private final int y;
        private final int size1;
        private final int size2;
        private final int shape;
        private final Color color;
        private final int rotation;
        private final String text;

        public PaintPoint(int x, int y, int size1, int size2, int shape, Color color, int rotation, String text) {
            this.x = x;
            this.y = y;
            this.size1 = size1;
            this.size2 = size2;
            this.shape = shape;
            this.color = color;
            this.rotation = rotation;
            this.text = text;
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
                case 5 -> {
                    int[] xPoints = {x, x - size1 / 2, x + size1 / 2};
                    int[] yPoints = {y - size2 / 2, y + size2 / 2, y + size2 / 2};
                    g2d.fillPolygon(xPoints, yPoints, 3);
                }
                case 6 -> {
                    g2d.setFont(new Font("Serif", Font.PLAIN, size1));
                    g2d.drawString(text, x, y);
                }
            }
            g2d.setTransform(old);
        }
    }
    PaintPanel() {
        setResizable(true);
        setSize(1000,1000);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        drawingPanel = new DrawingPanel();
        add(drawingPanel, BorderLayout.CENTER);
        add(new Toolbar(), BorderLayout.SOUTH);
        NorthPanel northPanel = new NorthPanel(this);
        this.add(northPanel, BorderLayout.NORTH);
        setVisible(true);
    }
    class Toolbar extends JToolBar{
        Toolbar(){
            setLayout(new GridLayout(1,5));



            //SET SIZE
            JPanel jp1 = new JPanel(new BorderLayout());
            JPanel jp1_2 = new JPanel(new GridLayout(2,1));
            JLabel jl1 = new JLabel("size");
            jl1.setHorizontalAlignment(SwingConstants.CENTER);
            jp1.add(jl1, BorderLayout.NORTH);
            SpinnerNumberModel spinnerModel = new SpinnerNumberModel(1, 1, 100, 1);
            JSpinner spinner = new JSpinner(spinnerModel);

            spinner.setFont(ProgramFont);
            spinner.addChangeListener(e -> currentSize = (Integer) spinner.getValue());
            jp1_2.add(spinner);


            //TEXT
            tx = new JTextField();
            jp1_2.add(tx);

            jp1.add(jp1_2);
            add(jp1);



            //TOOLS
            JPanel jp3 = new JPanel(new BorderLayout());
            JPanel jp3_2 = new JPanel(new GridLayout(2,1));
            JLabel jl3 = new JLabel("tools");
            jl3.setHorizontalAlignment(SwingConstants.CENTER);

            JToggleButton JRbrush = new JToggleButton(new ImageIcon("brush.png"));
            JRbrush.addActionListener(new ButtonActionListener(false));

            JToggleButton JRspray = new JToggleButton(new ImageIcon("spray.png"));
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

            JPanel jp9 = new JPanel(new BorderLayout());
            JLabel jl9 = new JLabel("functions");
            jp9.add(jl9, BorderLayout.NORTH);
            jl9.setHorizontalAlignment(SwingConstants.CENTER);

            JPanel jp9_2 = new JPanel(new GridLayout(2,2));
            JButton setBackGround = new JButton(new ImageIcon("background.png"));
            setBackGround.addActionListener(e -> drawingPanel.setBackground(currentColor));
            jp9_2.add(setBackGround);


            JToggleButton bigShape = new JToggleButton(new ImageIcon("bigshape.png"));
            JToggleButton randomRot = new JToggleButton(new ImageIcon("rotate.png"));
            JToggleButton gradient = new JToggleButton(new ImageIcon("gradient.png"));
            gradient.addActionListener(e -> isGradienting = !isGradienting);
            jp9_2.add(gradient);

            bigShape.addActionListener(e -> {
                isBigShape = !isBigShape;
                JRbrush.setEnabled(!JRbrush.isEnabled());
                JRspray.setEnabled(!JRspray.isEnabled());
                randomRot.setSelected(false);
            });
            jp9_2.add(bigShape);

            randomRot.addActionListener(e -> {
                isRandomRotating = randomRot.isSelected();
                isBigShape = false;
                JRbrush.setEnabled(true);
                JRspray.setEnabled(true);
                bigShape.setSelected(false);
            });
            jp9_2.add(randomRot);
            jp9.add(jp9_2);
            add(jp9);

            //SHAPES
            JPanel jp4 = new JPanel(new BorderLayout());
            JLabel jl4 = new JLabel("Shapes");
            jl4.setHorizontalAlignment(SwingConstants.CENTER);
            jp4.add(jl4, BorderLayout.NORTH);
            JPanel jp4_2 = new JPanel(new GridLayout(3,2));
            ButtonGroup ShapeGroup = new ButtonGroup();
            CreateShapeButton(new ImageIcon("circle.png"),      0, ShapeGroup, jp4_2);
            CreateShapeButton(new ImageIcon("circle_fill.png"),  1, ShapeGroup, jp4_2);
            CreateShapeButton(new ImageIcon("square.png"),      2, ShapeGroup, jp4_2);
            CreateShapeButton(new ImageIcon("square_fill.png"),  3, ShapeGroup, jp4_2);
            CreateShapeButton(new ImageIcon("triangle.png"),  4, ShapeGroup, jp4_2);
            CreateShapeButton(new ImageIcon("triangle_fill.png"),  5, ShapeGroup, jp4_2);
            CreateShapeButton(new ImageIcon("abc.png"),  6, ShapeGroup, jp4_2);

            jp4.add(jp4_2);
            add(jp4);



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
            red.addChangeListener(e -> {
                currentRed = red.getValue();
                UpdateColor();
                jl7_2.setText(String.format("#%02x%02x%02x", currentRed, currentGreen, currentBlue));
                rval.setText(String.valueOf(currentRed));
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
            green.addChangeListener(e -> {
                currentGreen = green.getValue();
                UpdateColor();
                jl7_2.setText(String.format("#%02x%02x%02x", currentRed, currentGreen, currentBlue));
                gval.setText(String.valueOf(currentGreen));
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
            blue.addChangeListener(e -> {
                currentBlue = blue.getValue();
                UpdateColor();
                jl7_2.setText(String.format("#%02x%02x%02x", currentRed, currentGreen, currentBlue));
                bval.setText(String.valueOf(currentBlue));
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
            AddColor.addActionListener(e -> {
                for (int i = colorButtons.size() - 1; i > 0; i--) {
                    Color previousColor = colorButtons.get(i - 1).getBackground();
                    colorButtons.get(i).setBackground(previousColor);
                }
                colorButtons.getFirst().setBackground(currentColor);
            });
            jp8_2.add(AddColor, BorderLayout.NORTH);

            JPanel jp8_3 = new JPanel(new GridLayout(3,4));


            for (int i = 0; i<12; i++){
                JButton btn = new JButton();
                colorButtons.add(btn);
                btn.setBackground(Color.WHITE);
                btn.addActionListener(e -> {
                    Color temp = btn.getBackground();
                    colorPlate.setBackground(temp);
                    red.setValue(temp.getRed());
                    green.setValue(temp.getGreen());
                    blue.setValue(temp.getBlue());
                });
                jp8_3.add(btn);
            }
            jp8_2.add(jp8_3);
            jp8.add(jp8_2);
            add(jp8);
        }
        void UpdateColor(){
            currentColor = new Color(currentRed, currentGreen, currentBlue);
            colorPlate.setBackground(currentColor);
        }
        void CreateShapeButton(ImageIcon ShapeIcon ,int sp, ButtonGroup bg, JPanel jp){
            JToggleButton Shape = new JToggleButton(ShapeIcon);
            Shape.addActionListener(e -> currentShape = sp);
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
    }
    class DrawingPanel extends JPanel implements MouseListener, MouseMotionListener, KeyListener, MouseWheelListener  {

        DrawingPanel(){
            setBackground(Color.WHITE);
            addMouseListener(this);
            addMouseMotionListener(this);
        }
        private void addPoint(MouseEvent e) {
            PaintPoint paintPoint = null;
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

            if(isGradienting){
                Gradient();
            }else{
                currentColor = new Color(currentRed,currentGreen,currentBlue);
            }

            if(currentShape == 6){
                paintPoint = new PaintPoint(x, y, currentSize, currentSize, currentShape, currentColor, rot, tx.getText());
            }
            else {
                paintPoint = new PaintPoint(x, y, currentSize, currentSize, currentShape, currentColor, rot, null);
            }
            paintPoints.add(paintPoint);
            repaint();
        }

        void Gradient(){
            Random random = new Random();
            int newRed = currentRed + random.nextInt(50)-25;
            int newGreen = currentGreen + random.nextInt(50)-25;
            int newBlue = currentBlue + random.nextInt(50)-25;

            if(newRed>255)newRed = 255;
            if(newGreen>255)newGreen = 255;
            if(newBlue>255)newBlue = 255;

            if(newRed<0)newRed = 0;
            if(newGreen<0)newGreen = 0;
            if(newBlue<0)newBlue = 0;

            currentColor = new Color(newRed,newGreen,newBlue);
        }

        private void addBigPoint() {
            if(isGradienting){
                Gradient();
            }else{
                currentColor = new Color(currentRed,currentGreen,currentBlue);
            }
            PaintPoint paintPoint = new PaintPoint((StartX + EndX) / 2, (StartY + EndY) / 2, ShapeW, ShapeH, currentShape, currentColor, 0, tx.getText());
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
            //isDrawing = true;
            if(!isBigShape) {
                addPoint(e);
            }
        }
        public void mouseMoved(MouseEvent e) {

        }
        @Override
        public void mouseReleased(MouseEvent e) {
            //isDrawing = false;

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
                addBigPoint();
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
