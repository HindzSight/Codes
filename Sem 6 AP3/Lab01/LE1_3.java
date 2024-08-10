/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
public class Main
{
	public static void main(String[] args) {
		int n= Integer.parseInt(args[0]);
		int temp=0;
		for(int i=1;i<=10;++i){
		    temp=n*i;
		  /*System.out.print(n);
		    System.out.print(" * ");
		    System.out.print(i);
		    System.out.print(" = ");
		    System.out.println(temp);
		  */
		  System.out.printf("%d * %d = %d\n", n,i,temp); 
		}
	}
}
