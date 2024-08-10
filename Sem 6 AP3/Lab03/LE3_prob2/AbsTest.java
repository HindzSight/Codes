interface Testable{
        void display();
    }
public abstract class AbsTest implements Testable{
    public void display(){
        System.out.println("Inside absTest class");
    }
}