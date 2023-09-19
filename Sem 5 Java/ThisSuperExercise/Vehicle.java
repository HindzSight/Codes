public class Vehicle{
	protected String brand;
	protected String color;
	protected String type;

	public Vehicle(String brand,String color,String type){
		this.brand = brand;
		this.color = color;
		this.type = type;
	}

	public void displayBrand(){
		System.out.println("Brand : "+brand);
		System.out.println("Color : "+color);
		System.out.println("\n");
	}

	public void displayInfo(){
		this.displayBrand();
		System.out.println("Type : "+type);	
		System.out.println("\n");
	}
}