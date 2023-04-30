#include<stdio.h>
void main()
{
	int n,j=1,a[5],i,min,lenof;
	printf("Enter the integers:");
	lenof=sizeof(a)/sizeof(int);
	for(i=0;i<lenof;i++)
	scanf("%d",&a[i]);
	min=a[0];
	for(n=1;n<lenof;n++)
	if(a[n]>a[n+1])
	min=a[n+1];
	printf("The smallest integer is %d",min);
}
