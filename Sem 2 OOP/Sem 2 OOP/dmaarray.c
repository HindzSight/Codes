#include<stdio.h>
#include <stdlib.h>
int main()
{
	int r,c,i,j;
	printf("Enter the value of Rows and Columns ");
	scanf("%d %d",&r,&c);
	int **ptr=(int**)malloc(r*sizeof(int));
	for(i=0;i<r;i++)
	ptr[i]=(int*)malloc(c*sizeof(int));
	if(ptr==NULL)
	{
		printf("Memory overflow");
		exit(0);
	}
	else
	{
		printf("enter the elements of matrix");
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
		scanf("%d",&ptr[i][j]);
		}
	}
}
