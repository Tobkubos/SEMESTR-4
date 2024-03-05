public abstract class Person {
    public abstract String getDescription();

    private String name;
    private String surname;

    public Person(String name, String surname){
        this.name = name;
        this.surname = surname;
    }
    public String GetName(){
        return name;
    }

    public String GetSurname(){
        return surname;
    }

    public void Eat(String item){
        System.out.println(name + " ZJADL " + item);
    }

}
