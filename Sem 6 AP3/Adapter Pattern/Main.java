public class Main
{
	public static void main(String[] args) {
		System.out.println("Adapter Pattern");
		System.out.println();
		Crow crow = new IndianCrow();
		CrowAdapter crowadapter = new CrowAdapter(crow);
		client(crowadapter);
	}
	public static void client(Swan swan){
	    swan.eat();
	    swan.swim();
	    swan.sing();
	}
}
