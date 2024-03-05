import  java.util.GregorianCalendar;
import  java.util.Date;

public class Employee extends Person {

    private float salary;
    private Date hireDate;

    @Override
    public String getDescription() {
        return " SALARY: " + salary + " HIRE DATE: " + hireDate;
    }

    public Employee(String n, String su, float sal, int year, int month, int day, int h, int m, int s) {
        super(n, su);
        GregorianCalendar cal =  new GregorianCalendar(year, month,day, h, m ,s);
        hireDate  = cal.getTime();
        salary = sal;
    }

}
