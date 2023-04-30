#include<stdio.h>
int main()
{
int a[25]={},c,i;
printf("Enter No.");
for(i=0;i<25;i++)
{
scanf("%d",&a[i]);
}
c=(sizeof(a[i])/sizeof(int));
printf("The number of digits is %d",c);

return 0;
}
