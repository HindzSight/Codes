#include<stdio.h>
int main()
{
	int i,j=7,n,c;
	printf("Enter the number");
	scanf("%d",&i);
	n=(i/7)+1;
	c=n*j;
	printf("The next largest multiple of 7 is %d",c);
	return 0;
}
