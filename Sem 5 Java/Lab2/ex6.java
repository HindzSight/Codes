public class ex6{
    public static void main(String[] args) {
        int [] arr = new int [] {1,2,3,4,5};;
        int sum = 0 ;
        int i ;
        for(i = 0 ; i < arr.length ; ++i)
        {
            System.out.print(arr[i] + " ");
            sum += arr[i];
        }
        System.out.println("Sum = "+sum);
    }
}