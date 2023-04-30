#include<stdio.h>
int main()
{
	int num,m,n;
	srand(time(0));
	printf("Enter the min:\n");
	scanf("%d",&m);
	printf("Enter the max:\n");
	scanf("%d",&n);
	num=(rand() %(m-n+1) + m);
	printf("Random:%d",num);
	return 0;
}
