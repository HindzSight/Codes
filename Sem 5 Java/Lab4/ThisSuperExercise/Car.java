public class Car extends Vehicle{
	private String model;
	private int year;

	public Car(String brand,String model,int year,String color){
		super(brand,color,"Car");
		this.model = model;
		this.year = year;
	}

	public void displayCarInfo(){
		System.out.println("Car Info:");
		super.displayBrand();
		System.out.println("Model: " + model);
		System.out.println("Year: " + year);
	}

	public void displayBrand(){
		System.out.println("Car Info:");
		super.displayBrand();
		System.out.println("Year: " + year);

	}
}