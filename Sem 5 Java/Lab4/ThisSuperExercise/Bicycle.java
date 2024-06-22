public class Bicycle extends Vehicle{
	protected int gears;

	public Bicycle(String brand,int gears,String color){
		super(brand,color,"Bicycle");
		this.gears = gears;
	}

	public void displayBicycleInfo(){
		System.out.println("Bicycle Info:");
		super.displayBrand();
		System.out.println("Gears: " + gears);
	}
}