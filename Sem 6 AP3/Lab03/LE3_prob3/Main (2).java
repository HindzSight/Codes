public class Main
{
	public static void main(String[] args) {
		System.out.println("RubberDucks");
		RD t1 = new RD();
		t1.sound();
		t1.swim();
		System.out.println("WoodenDucks");
		WD t2 = new WD();
		t2.swim();
		System.out.println("RedHeadDucks");
		RHD t3 = new RHD();
		t3.sound();
		t3.fly();
		t3.swim();
		System.out.println("LakeDucks");
		LD t4 = new LD();
		t4.sound();
		t4.fly();
		t4.swim();
	}
}
