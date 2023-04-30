#include<stdio.h>
int main()
{
	int r,c,i,j;
	printf("Enter the value of Rows and Columns ");
	scanf("%d %d",&r,&c)
	int **ptr=(int**)malloc(r*sizeof(int));
	for(i=0;i<r;i++)
	ptr[i]=(int*)malloc(c*sizeof(int))
	if(ptr==NULL)
	{
		printf("Memory overflow");
		exit(0);
	}
	else
	{
		for(i=0,j=0;i<r,j<c;i++,j++)
		scanf("%d",ptr[i][j]);
	}
}
