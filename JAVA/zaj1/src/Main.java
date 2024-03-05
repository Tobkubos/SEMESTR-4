//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {


        Person[] people = new Person[4];
        people[0] = new Student("Adam", "Kowalski", "Informatyka");
        people[1] = new Student("Andrzej", "Kot", "Informatyka Stosowana");
        people[2] = new Student("Anastazy", "Kowal", "Informatyka Niestosowana");

        people[3] = new Employee("Robert", "Biedroń", 25000, 1410, 11, 15, 10, 25, 11);

        for (Person person : people) {
            if(person!= null){
                System.out.println("NAME: " + person.GetName() + " SURNAME: " + person.GetSurname() + person.getDescription() + "\n");
            }
        }

        people[2].Eat("NIETOPERZ");
    }
}