import javax.swing.*;
import javax.swing.border.LineBorder;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

class CustomButton extends JButton {
    public CustomButton(String text, String iconPath) {
        super(text);
        ImageIcon icon = new ImageIcon(iconPath);
        Image image = icon.getImage().getScaledInstance(30, 30, Image.SCALE_SMOOTH);
        setIcon(new ImageIcon(image));
        setFont(new Font("Arial", Font.BOLD, 14));
        setBackground(Color.BLACK);
        setForeground(new Color(0xB5C2B7));
        setBorder(new LineBorder(new Color(0xB5C2B7)));

        addMouseListener(new MouseAdapter() {
            @Override
            public void mouseEntered(MouseEvent e) {
                setBackground(new Color(0x2D2327));
            }

            @Override
            public void mouseExited(MouseEvent e) {
                setBackground(Color.BLACK);
            }
        });
    }
}