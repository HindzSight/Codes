/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
public class Main
{
    public static void fun1(int n){
		for(int i=0;i<n;++i){
		    for(int k=0;k<n-i-1;++k){
		        System.out.print(" ");
		    }
		    for(int j=0;j<i;++j){
		        System.out.print("* ");
		    }
		    System.out.print("\n");
		}
        
    }

    public static void fun2(int n) {
		for(int i=0;i<n;++i){
		    for(int k=0;k<i;++k){
		        System.out.print(" ");
		    }
		    for(int j=0;j<n-i-1;++j){
		        System.out.print(" *");
		    }
		    System.out.print("\n");
		}
    }
	public static void main(String[] args) {
		int n= Integer.parseInt(args[0]);
		fun1(n);
		System.out.println();
		fun2(n);
	}
}
