import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.ListIterator;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        LinkedList<String> a = new LinkedList<>();
        a.add("Andrzej");
        a.add("Ania");
        a.add("Agata");
        a.add("Alojzy");

        LinkedList<String> b = new LinkedList<>();
        b.add("Bartek");
        b.add("Basia");
        b.add("Bogdan");
        b.add("Bogumił");
        b.add("Bogdanoff");
        b.add("BigShaq");


        ListIterator<String> a1 = a.listIterator();
        Iterator<String> b1 = b.iterator();

        //1
        while (a1.hasNext()) {
            a1.next();
            if(b1.hasNext()){
                a1.add(b1.next());
            }
        }
        while(b1.hasNext()){
            a1.add(b1.next());
        }
        System.out.println(a);

        //2
        Iterator<String> b2 = b.iterator();
        boolean com = true;
        while(b2.hasNext())
        {
            com = !com;
            if(com)
            {
                b2.remove();
            }
            b2.next();
        }

        //3
        a.removeAll(b);


        System.out.println(b);
        System.out.println(a);
    }
}