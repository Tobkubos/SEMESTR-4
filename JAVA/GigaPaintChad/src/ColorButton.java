import javax.swing.*;
import java.awt.*;

public class ColorButton extends JButton {
    public ColorButton(Color backgroundColor) {
        this.setBackground(backgroundColor);
        this.setPreferredSize(new Dimension(20, 20));
    }
}
