
import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

public class NorthPanel extends JPanel {

    private PaintPanel paintPanel;

    NorthPanel(PaintPanel paintPanel) {
        this.paintPanel = paintPanel;
        this.setLayout(new FlowLayout(FlowLayout.LEFT, 0,0));
        JMenuBar MenuBar = new JMenuBar();

        JMenuItem File_New = new JMenuItem(new MyAction("New"));
        JMenuItem About = new JMenuItem(new MyAction("About"));
        JMenuItem Load = new JMenuItem(new LoadAction("Load"));
        JMenuItem Save = new JMenuItem(new SaveAction("Save"));
        JMenuItem Undo = new JMenuItem(new UndoAction("Undo"));
        Undo.setAccelerator(KeyStroke.getKeyStroke("ctrl Z"));
        JMenuItem Redo = new JMenuItem(new RedoAction("Redo"));
        Redo.setAccelerator(KeyStroke.getKeyStroke("ctrl Y"));
        JMenuItem Clear = new JMenuItem(new ClearAllAction("Clear"));
        JMenuItem Exit = new JMenuItem(new ExitAction("Exit"));

        MenuBar.add(File_New);
        MenuBar.add(About);
        MenuBar.add(Undo);
        MenuBar.add(Redo);
        MenuBar.add(Clear);
        MenuBar.add(Load);
        MenuBar.add(Save);
        MenuBar.add(Exit);

        this.setVisible(true);
        this.add(MenuBar);
    }
    private class MyAction extends AbstractAction {

        public MyAction(String name) {

            super(name);
        }

        public void actionPerformed(ActionEvent e) {

            System.out.println(e.getActionCommand());
        }
    }

    private class LoadAction extends AbstractAction {
        public LoadAction(String name) {

            super(name);
        }
        public void actionPerformed(ActionEvent e) {
            JFileChooser fileChooser = new JFileChooser();
            int returnValue = fileChooser.showDialog(null, "Wybierz");
            if (returnValue == JFileChooser.APPROVE_OPTION) {
                File selectedFile = fileChooser.getSelectedFile();
                try {
                    paintPanel.image = ImageIO.read(selectedFile);
                    paintPanel.repaint();
                    paintPanel.setSize(paintPanel.getWidth()+1, paintPanel.getHeight());

                } catch (IOException exception) {
                    exception.printStackTrace();
                }
            }
        }
    }

    private class SaveAction extends AbstractAction {
        public SaveAction(String name) {

            super(name);
        }
        public void actionPerformed(ActionEvent e) {
            Dimension dim = paintPanel.drawingPanel.getSize();
            BufferedImage image = new BufferedImage(dim.width, dim.height, BufferedImage.TYPE_INT_RGB);

            Graphics2D g = image.createGraphics();
            paintPanel.drawingPanel.paint(g);
            g.dispose(); //zwalnienie pamieci

            JFileChooser fileChooser = new JFileChooser();
            int returnValue = fileChooser.showDialog(null, "Zapisz");

            if (returnValue == JFileChooser.APPROVE_OPTION) {
                File file = fileChooser.getSelectedFile();
                file = new File(file.getAbsolutePath() + ".png");
                try {
                    ImageIO.write(image, "png", file);
                    JOptionPane.showMessageDialog(null, "Zapisano pomyślnie w " + file.getAbsolutePath());
                } catch (IOException ex) {
                    ex.printStackTrace();
                    JOptionPane.showMessageDialog(null, "Błąd zapisu");
                }
            }
        }
    }


    private class ExitAction extends AbstractAction {
        public ExitAction(String name) {

            super(name);
        }
        public void actionPerformed(ActionEvent e) {

            System.exit(0);
        }
    }

    private class UndoAction extends AbstractAction {
        public UndoAction(String name) {

            super(name);
        }
        public void actionPerformed(ActionEvent e) {
            if(!paintPanel.paintPoints.isEmpty()) {
                paintPanel.RedoPaintPoints.add(paintPanel.paintPoints.getLast());
                paintPanel.paintPoints.removeLast();
                repaint();
            }

        }
    }

    private class RedoAction extends AbstractAction {
        public RedoAction(String name) {

            super(name);
        }
        public void actionPerformed(ActionEvent e) {
            if(!paintPanel.RedoPaintPoints.isEmpty()) {
                paintPanel.paintPoints.add(paintPanel.RedoPaintPoints.getLast());
                paintPanel.RedoPaintPoints.removeLast();
                repaint();
            }

        }
    }

    private class ClearAllAction extends AbstractAction {
        public ClearAllAction(String name) {

            super(name);
        }
        public void actionPerformed(ActionEvent e) {
            paintPanel.paintPoints.clear();
            paintPanel.image = null;
            repaint();
        }
    }
}