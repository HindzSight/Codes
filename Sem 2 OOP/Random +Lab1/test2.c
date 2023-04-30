#include<stdio.h>
void main()
{
	int i,a[5],length;
	length=sizeof(a)/sizeof(a[0]);
	printf("Enter the integers");
	for(i=0;i<length;i++)
	scanf("%d",&a[i]);
	minmax(&a[0],&a[0],length);
}

int minmax(int *min,int *max,int len)
{
	int n,j,l,s;
	l=max[0];
	s=min[0];
	for(n=1;n<len;n++)
	if(min[n]<l)
	l=min[n];
	printf("The smallest integer is %d\t",l);
	j=1;
	for(n=1;n<len;n++)
	if(max[n]>s)
	s=min[n];
	printf("The largest integer is %d\t",s);
}
