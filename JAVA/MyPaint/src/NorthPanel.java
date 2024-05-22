
import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

public class NorthPanel extends JPanel {

    private final PaintPanel paintPanel;

    NorthPanel(PaintPanel paintPanel) {
        this.paintPanel = paintPanel;
        this.setLayout(new FlowLayout(FlowLayout.LEFT, 0,0));
        JMenuBar MenuBar = new JMenuBar();

        JMenu fileMenu = new JMenu("file");
        JMenu editMenu = new JMenu("edit");


        //1
        JMenuItem Load = new JMenuItem(new LoadAction("Load"));
        JMenuItem Save = new JMenuItem(new SaveAction("Save"));
        Save.setAccelerator(KeyStroke.getKeyStroke("ctrl S"));
        JMenuItem Exit = new JMenuItem(new ExitAction("Exit"));


        //2
        JMenuItem Undo = new JMenuItem(new UndoAction("Undo"));
        Undo.setAccelerator(KeyStroke.getKeyStroke("ctrl Z"));

        JMenuItem Redo = new JMenuItem(new RedoAction("Redo"));
        Redo.setAccelerator(KeyStroke.getKeyStroke("ctrl Y"));

        JMenuItem Clear = new JMenuItem(new ClearAllAction("Clear"));


        //3
        JMenuItem About = new JMenuItem(new AboutAction("About"));



        //----------------
        fileMenu.add(Load);
        fileMenu.add(Save);
        fileMenu.addSeparator();
        fileMenu.add(Exit);

        editMenu.add(Undo);
        editMenu.add(Redo);
        editMenu.addSeparator();
        editMenu.add(Clear);

        MenuBar.add(fileMenu);
        MenuBar.add(editMenu);
        MenuBar.add(About);

        this.setVisible(true);
        this.add(MenuBar);
    }

    private static class AboutAction extends AbstractAction {

        public AboutAction(String name) {

            super(name);
        }

        public void actionPerformed(ActionEvent e) {
            JDialog aboutDialog = new JDialog((Frame) null, "About", true);
            aboutDialog.setLayout(new BorderLayout());
            aboutDialog.setSize(300, 150);
            aboutDialog.setLocationRelativeTo(null); //centrum

            //label
            JLabel aboutLabel = new JLabel("GigaPaint'cior stworzony przez: Tobiasz Kubiak", SwingConstants.CENTER);
            aboutDialog.add(aboutLabel, BorderLayout.CENTER);

            //close btn
            JButton closeButton = new JButton("Gicior");
            closeButton.addActionListener(ev -> aboutDialog.dispose());
            JPanel buttonPanel = new JPanel();
            buttonPanel.add(closeButton);
            aboutDialog.add(buttonPanel, BorderLayout.SOUTH);

            aboutDialog.setVisible(true);
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

                } catch (IOException ex) {
                    ex.printStackTrace();
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


    private static class ExitAction extends AbstractAction {
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
            paintPanel.drawingPanel.setBackground(Color.WHITE);
        }
    }
}