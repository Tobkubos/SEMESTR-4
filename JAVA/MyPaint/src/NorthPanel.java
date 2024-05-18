
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class NorthPanel extends JPanel {

    NorthPanel() {
        this.setLayout(new FlowLayout(FlowLayout.LEFT, 0,0));
        JMenuBar MenuBar = new JMenuBar();

        JMenuItem File_New = new JMenuItem(new MyAction("New"));
        JMenuItem About = new JMenuItem(new MyAction("About"));
        JMenuItem Exit = new JMenuItem(new ExitAction("Exit"));

        MenuBar.add(File_New);
        MenuBar.add(About);
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

    private class ExitAction extends AbstractAction {
        public ExitAction(String name) {

            super(name);
        }
        public void actionPerformed(ActionEvent e) {

            System.exit(0);
        }
    }
}