import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

public class Zad2 {
    public static void main(String[] args) {

        class Employee{
            private int id;
            private String name, surname;

            Employee(String name, String surname){
                this.name = name;
                this.surname = surname;
            }
        }


        Map<String, Employee> staff = new HashMap<>();
        Iterator<Map.Entry<String,Employee>> s = staff.entrySet().iterator();
        staff.put("123", new Employee("Lowert", "Rewandowski"));
        staff.put("456", new Employee("Kylian", "Mekambe"));
        staff.put("789", new Employee("Cristiano", "Rolando"));

        staff.remove("123");


    }
}
