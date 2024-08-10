public class Main
{
	public static void main(String[] args) {
		System.out.println("Beer : ");
		Beverage b = new Beer();
		b.templateMethod(300);
		
		System.out.println("\nRum : ");
	    b = new Rum();
	    b.templateMethod(30);
	    
	    System.out.println("\nWhiskey : ");
	    b = new Whiskey();
	    b.templateMethod(60);
	    
	    System.out.println("\nWhiskey-2 : ");
	    Whiskey w = new Whiskey();
	    w.templateMethod(60);
	    
	}
}
