import java.io.*;
import java.time.LocalDate;
import java.util.Arrays;

class Employee implements Serializable {
    private String name;
    private double pensja;
    private LocalDate data;

    public Employee(String name, double pensja, LocalDate data) {
        this.name = name;
        this.pensja = pensja;
        this.data = data;
    }

    public void DajPodwyzke(double podw) {
        this.pensja += podw;
    }
    public String toString() {
        return "IMIE=" + name + "  PENSJA " + pensja + "  DATA ZATR:" + data;
    }
}

class Manager extends Employee {
    private Employee assistant;

    public Manager(String name, double pensja, LocalDate data) {
        super(name, pensja, data);
    }

    public void assignAssistant(Employee assistant) {
        this.assistant = assistant;
    }



}


public class Main2 {
    void Makeemps(){
        Employee emp1 = new Employee("CRISTIAN", 500, LocalDate.of(2020, 1, 15));
        Employee emp2 = new Employee("MESI", 55000, LocalDate.of(2019, 3, 22));
        Manager man1 = new Manager("LEWANDOSKI", 60000, LocalDate.of(2018, 5, 30));
        Manager man2 = new Manager("SZCZEZNY", 65000, LocalDate.of(2017, 11, 11));

        man1.assignAssistant(emp2);
        man2.assignAssistant(emp2);

        Employee[] employees = {emp1, emp2, man1, man2};

        System.out.println(employees[0]);
        System.out.println(employees[1]);
        System.out.println(employees[2]);
        System.out.println(employees[3]);
    }
    public static void main(String[] args) {

     public static void ReadObj() throw new RuntimeException();
    }
}