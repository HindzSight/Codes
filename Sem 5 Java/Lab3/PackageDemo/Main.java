import package1.ClassA;
import package2.ClassB;
public class Main{
	public static void main(String[] args) {
		System.out.println("Main Function");
		ClassA a = new ClassA();
		ClassB b = new ClassB();
		a.displayA();
		b.displayB();
	}
}