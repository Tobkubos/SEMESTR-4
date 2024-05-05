
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MyFrame extends JFrame {

    public JCheckBoxMenuItem Edit_Options_ReadOnly;
    public JRadioButtonMenuItem Edit_Options_Insert;
    public JRadioButtonMenuItem Edit_Options_Overtype;
    MyFrame() {
        //FRAME
        this.setTitle("MenuTest");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setResizable(false);
        this.setSize(700, 700);

        JMenuBar MenuBar = new JMenuBar();

        JMenu fileMenu = new JMenu("File");
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
        fileMenu.addSeparator();
        JMenuItem Exit = fileMenu.add(new ExitAction("Exit"));

        File_Open.setAccelerator(KeyStroke.getKeyStroke("ctrl O"));
        File_Save.setAccelerator(KeyStroke.getKeyStroke("ctrl S"));


        //EDIT
        JMenuItem Edit_Paste = EditMenu.add(new MyAction("Paste"));
        JMenuItem Edit_Cut = EditMenu.add(new MyAction("Cut"));
        JMenuItem Edit_Copy = EditMenu.add(new MyAction("Copy"));
        Edit_Copy.setIcon(new ImageIcon("copy.png"));
        JMenu Edit_Options = new JMenu("Options");

        Edit_Paste.setAccelerator(KeyStroke.getKeyStroke("ctrl V"));
        Edit_Cut.setAccelerator(KeyStroke.getKeyStroke("ctrl X"));
        Edit_Copy.setAccelerator(KeyStroke.getKeyStroke("ctrl C"));

        EditMenu.addSeparator();
        EditMenu.add(Edit_Options);

        Edit_Options_ReadOnly = new JCheckBoxMenuItem("Read-only");
        Edit_Options_ReadOnly.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                boolean selected = Edit_Options_ReadOnly.isSelected();

                if (selected) {
                    Edit_Options_Overtype.setSelected(!selected);
                    Edit_Options_Insert.setSelected(!selected);
                }
                Edit_Options_Insert.setEnabled(!selected);
                Edit_Options_Overtype.setEnabled(!selected);
            }
        });

        boolean Insert = false;
        boolean Overtype = false;

        Edit_Options_Insert = new JRadioButtonMenuItem("Insert");
        ActionListener InsertAction = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Edit_Options_Insert.setSelected(true);
                Edit_Options_Overtype.setSelected(false);
                System.out.println(Edit_Options_Insert.isSelected());
                System.out.println(Edit_Options_Overtype.isSelected());
            }
        };
        Edit_Options_Insert.addActionListener(InsertAction);



        Edit_Options_Overtype = new JRadioButtonMenuItem("Overtype");
        ActionListener OvertypeAction = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Edit_Options_Insert.setSelected(false);
                Edit_Options_Overtype.setSelected(true);
                System.out.println(Edit_Options_Insert.isSelected());
                System.out.println(Edit_Options_Overtype.isSelected());
            }
        };
        Edit_Options_Overtype.addActionListener(OvertypeAction);



        Edit_Options.add(Edit_Options_ReadOnly);
        Edit_Options.addSeparator();
        Edit_Options.add(Edit_Options_Insert);
        Edit_Options.add(Edit_Options_Overtype);



        //HELP
        JMenuItem Help_Index = HelpMenu.add(new MyAction("Index"));
        JMenuItem Help_About = HelpMenu.add(new MyAction("About"));
        Help_Index.setMnemonic('I');
        Help_About.setMnemonic('H');

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

    private class ExitAction extends AbstractAction {
        public ExitAction(String name) {

            super(name);
        }
        public void actionPerformed(ActionEvent e) {

            System.exit(0);
        }
    }
}