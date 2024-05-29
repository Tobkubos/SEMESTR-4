import java.util.ArrayList;
import java.util.Date;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {





    public static void main(String[] args) {

        class Employee{
            String name = null;
            int pensja = 0;
            Date dataZatrudnienia = null;

            Employee(String name, int pensja, Date data){
                this.name = name;
                this.pensja = pensja;
                this.dataZatrudnienia = data;
            }

            void DajPodwyzke(int podwyzka){
                this.pensja += podwyzka;
            }

            @Override
            public String toString() {
                return this.name +"     "+this.pensja +"    "+ this.dataZatrudnienia;
            }
        }

        ArrayList<Employee> emps = new ArrayList<>();
        emps.add(new Employee("ADAM MAŁYSZ", 6900, new Date(2024,12,15,12,12,12)));
        emps.add(new Employee("CRISTIANO ROLANDO", 120000, new Date(2015,10,4,0,0,0)));
        emps.add(new Employee("LION BESSI", 1450000, new Date(1999,4,2,3,3,3)));

        System.out.println(emps.get(0));
        System.out.println(emps.get(1));
        System.out.println(emps.get(2));

    }
}