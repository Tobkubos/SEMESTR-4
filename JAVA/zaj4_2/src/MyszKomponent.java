import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;

import java.util.*;
import javax.swing.*;


public class MyszKomponent extends JComponent {

   private static final int dszerokosc = 600;
   private static final int dwysokosc = 600;

   private static final int promien = 10;

   private ArrayList<Ellipse2D> kolo;
   private Ellipse2D aktualne;

   public MyszKomponent() {
      kolo = new ArrayList<>();
      aktualne = null;
      addMouseListener(new SluchaczMyszy());
      addMouseMotionListener(new RuchMyszy());
   }

   public void paintComponent(Graphics g) {
      Graphics2D g2 = (Graphics2D) g;

      for (Ellipse2D e : kolo)
         g2.draw(e);


   }

   public Ellipse2D find(Point2D p) {
      for (Ellipse2D e : kolo) {
         if (e.contains(p)) return e;
      }
      return null;
   }

   public void add(Point2D p) {
      double x = p.getX();
      double y = p.getY();

      aktualne = new Ellipse2D.Double(x-promien, y - promien, promien * 2, promien * 2);
      kolo.add(aktualne);
      repaint();

   }

   public void remove(Ellipse2D s) {
      if (s == null) return;
      if (s == aktualne) aktualne = null;
      kolo.remove(s);
      repaint();

   }

   private class SluchaczMyszy extends MouseAdapter {



      public void mousePressed(MouseEvent event) {
       //  if ((event.getModifiers() & InputEvent.BUTTON3_MASK) != 0) {  //prawy przycisk myszy
         aktualne = find(event.getPoint());
         if (aktualne == null) add(event.getPoint());

      }

      public void mouseClicked(MouseEvent event) {

         aktualne = find(event.getPoint());
         if (aktualne != null && event.getClickCount() >= 2) remove(aktualne);

      }
   }

   public Dimension getPreferredSize() {
      return new Dimension(dszerokosc, dwysokosc);
   }


   private class RuchMyszy implements MouseMotionListener {
      public void mouseMoved(MouseEvent event) {

         if (find(event.getPoint()) == null) setCursor(Cursor.getDefaultCursor());
         else setCursor(Cursor.getPredefinedCursor(Cursor.CROSSHAIR_CURSOR));

      }

      public void mouseDragged(MouseEvent event) {

         if (aktualne != null) {
            int x = event.getX();
            int y = event.getY();

            aktualne.setFrame(x - promien, y - promien, promien * 2, promien * 2);
            repaint();

         }
      }
   }
}