import javax.swing.*;

public class Main {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                PokaObraz();
            }
        });
    }

    private static void PokaObraz() {
        JFrame frame = new JFrame("Rysowanie za pomocą myszy");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        frame.add(new MyszKomponent());

        frame.pack();
        frame.setVisible(true);
    }
}