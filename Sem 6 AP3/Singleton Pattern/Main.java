public class Main
{
	public static void main(String[] args) {
		Singleton S1 = Singleton.getInstance();
		Singleton S2 = Singleton.getInstance();
		if(S1 == S2){
		    System.out.println("Same Objects");
		}else{
		    System.out.println("Diff Objects");
		}
	}
}
