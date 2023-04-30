#include<stdio.h>
int main()
{
	int a[3][3]={1,2,3,4,5,6,12,11,10},b[3][3]={3,2,1,5,6,4,9,7,5},i,j,c[3][3];
    for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)		
    c[i][j]=a[i][j]+b[i][j];
    }
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)		
    printf("%d \t",c[i][j]);
    }
}
