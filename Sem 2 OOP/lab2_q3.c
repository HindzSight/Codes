#include<stdio.h>
void reverse(long double a[],int len)
{
	int i;
	long double b[5];
	for(i=0;i<len;i++)
	a[5-i]=b[i];
	for(i=0;i<len;i++)
	printf("%d",b[i]);
}

int main()
{
	int i,size;
	long double a[5];
	printf("Enter the number");
	size=sizeof(a)/sizeof(a[0]);
	for(i=0;i<5;i++)
	scanf("%Lf",&a[i]);
	reverse(a,size);
	return 0;
}
