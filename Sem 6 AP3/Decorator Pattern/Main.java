public class Main
{
	public static void main(String[] args) {
		Offering offering = new Coffee();
		offering = new Rum(offering);
		//offering = new Rum(offering);
		System.out.println(offering.getName());
		System.out.println(offering.getPrice());
		System.out.println();
		Offering offering2 = new Icecream();
		offering2 = new Soda(offering2);
		offering2 = new Rum(offering2);
		System.out.println(offering2.getName());
		System.out.println(offering2.getPrice());
	}
}
