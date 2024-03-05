public class Student extends Person {
    private String major;


    public Student(String n, String su, String m) {
        super(n, su);
        major = m;
    }

    @Override
    public String getDescription() {
        return (" MAJOR: " + major);
    }
}
