interface Testable{
        void display();
    }
public class Test implements Testable{
    public void display(){
        System.out.println("Inside test class");
    }
}