import com.sun.java.accessibility.util.EventID;

import javax.swing.*;
import javax.swing.text.TextAction;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.io.File;
import java.io.OutputStream;
import java.util.*;
public class MyFrame extends JFrame {

    MyFrame() {
        //FRAME
        this.setTitle("MenuTest");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setResizable(false);
        this.setSize(700, 700);

        JMenuBar MenuBar = new JMenuBar();

        JMenu fileMenu = new JMenu("File");
        ;
        JMenu EditMenu = new JMenu("Edit");
        JMenu HelpMenu = new JMenu("Help");

        MenuBar.add(fileMenu);
        MenuBar.add(EditMenu);
        MenuBar.add(HelpMenu);

        //FILES
        JMenuItem File_New = fileMenu.add(new MyAction("New"));
        JMenuItem File_Open = fileMenu.add(new MyAction("Open"));
        JMenuItem File_Save = fileMenu.add(new MyAction("Save"));
        JMenuItem File_Save_As = fileMenu.add(new MyAction("Save As"));
        JMenuItem Exit = fileMenu.add(new MyAction("Exit"));


        //EDIT
        JMenuItem Edit_Paste = editMenu.add(new MyAction("Paste"));
        JMenuItem Edit_Cut = fileMenu.add(new MyAction("Cut"));
        JMenuItem Edit_Copy = fileMenu.add(new MyAction("Copy"));
        JMenu Edit_Options = fileMenu.add(new MyAction("Options"));

        JCheckBoxMenuItem Edit_Options_ReadOnly = new JCheckBoxMenuItem("Read-only");
        JRadioButtonMenuItem Edit_Options_Insert = new JRadioButtonMenuItem("Insert");
        JRadioButtonMenuItem Edit_Options_Overtype = new JRadioButtonMenuItem("Overtype");

        Edit_Options.add(Edit_Options_ReadOnly);
        Edit_Options.addSeparator();
        Edit_Options.add(Edit_Options_Insert);
        Edit_Options.add(Edit_Options_Overtype);

        EditMenu.add(Edit_Paste);
        EditMenu.add(Edit_Cut);
        EditMenu.add(Edit_Copy);
        EditMenu.addSeparator();
        EditMenu.add(Edit_Options);

        //HELP
        JMenuItem Help_Index = new JMenuItem("Index");
        JMenuItem Help_About = new JMenuItem("About");
        HelpMenu.add(Help_Index);
        HelpMenu.add(Help_About);


        this.add(MenuBar, BorderLayout.NORTH);
        this.setVisible(true);
    }
    private class MyAction extends AbstractAction {

        public MyAction(String name) {
            super(name);
        }

        public void actionPerformed(ActionEvent e) {
            System.out.println(e.getActionCommand());
        }
    }
}