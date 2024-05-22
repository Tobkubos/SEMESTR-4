
import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
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
        JMenuItem Undo = new JMenuItem(new UndoAction("Undo"));
        Undo.setAccelerator(KeyStroke.getKeyStroke("ctrl Z"));
        JMenuItem Exit = new JMenuItem(new ExitAction("Exit"));

        MenuBar.add(File_New);
        MenuBar.add(About);
        MenuBar.add(Undo);
        MenuBar.add(Load);
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
            int returnValue = fileChooser.showOpenDialog(null);
            if (returnValue == JFileChooser.APPROVE_OPTION) {
                File selectedFile = fileChooser.getSelectedFile();
                try {
                    paintPanel.image = ImageIO.read(selectedFile);
                    repaint();
                    JFrame frame = (JFrame) SwingUtilities.getWindowAncestor(paintPanel);
                    frame.setSize(frame.getWidth()+1, frame.getHeight());

                } catch (IOException exception) {
                    exception.printStackTrace();
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
                paintPanel.paintPoints.removeLast();
                repaint();
            }

        }
    }
}