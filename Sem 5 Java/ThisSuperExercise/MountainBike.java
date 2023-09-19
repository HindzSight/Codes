public class MountainBike extends Bicycle{
	private String suspensionType;

	public MountainBike(String brand,int gears,String color,String suspensionType){
		super(brand,gears,color);
		this.suspensionType = suspensionType;
	}

	public void displaymountainBikeInfo(){
		System.out.println("Mountain Bike Info:");
		super.displayBicycleInfo();
		System.out.println("Suspension Type: " + suspensionType);
		System.out.println("\n");
	}
}