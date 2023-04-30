#include<stdio.h>
int f(int n)
{
if(n==0)
return 1;
else
 return n*f(n-1);
}
int main()
{
int i,j;
printf("Enter No:");
scanf("%d",&i);
j=f(i);
printf("Factorial is %d",j);
return 0;
}