public class CommandLineExample{
	public static void main(String[] args) {
		int sum = 0;
		for(int i = 0 ; i < args.length; ++i){
			int a = Integer.parseInt(args[i]);
			sum += a;
		}
		System.out.print("The sum is : " + sum);
	}
}