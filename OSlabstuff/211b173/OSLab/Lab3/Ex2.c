#include<stdio.h>

int main()
{
    int v_add;
    int base_code = 32;
    int base_heap = 34;
    int base_stack = 28;

    int a[14], n, i;
    printf("Enter Virtual Address to be relocated (in B): ");
    scanf("%d", &v_add);
    n = v_add;
    for(int j=0; j<14; j++)
    {
        a[j]=0;
    }
    for(i=0; n>0; i++)
    {
        a[i]=n%2;
        n= n/2;
    }
    int offset = 0;
    int place = 1;
    for(int k=0; k<12; k++)
    {
        offset = offset + place*a[k];
        place = place * 2;
    }

    if (a[13] == 0 && a[12] == 0)
    {
        if(offset > 2*1024)
        {
            printf("Segmentation Fault\n");
        }
        else
        {
            /*Code Segment*/
            int p_add = 0;
            p_add = offset + base_code*1024;
            printf("Physical Address : (in B) %d\n", p_add);
        }
    }
    else if (a[13] == 0 && a[12] == 1)
    {
        if(offset > 3*1024)
        {
            printf("Segmentation Fault\n");
        }
        else
        {
            /*Heap Segment*/
            int p_add = 0;
            p_add = offset + base_heap*1024;
            printf("Physical Address : (in B) %d\n", p_add);
        }
    }
    else if(a[13] == 1 && a[12] == 1)
    {
        if(offset > 2*1024)
        {
            printf("Segmentation Fault\n");
        }
        else
        {
            /*Stack Segment*/
            int p_add = 0;
            offset = offset - 4*1024;
            p_add = offset + base_stack*1024;
            printf("Physical Address : (in B) %d\n", p_add);
        }
    }
    else
    {
        printf("Segment fault;\n");
    }
    return 0;
}

/*
*     printf("Binary of the given number= ");
*     for(i=13 ; i>=0 ; i--)
*     {
*         printf("%d",a[i]); // Binary array reverse stored in a[14]
*     }
*
*
*         a[13] a[12]\
*         0      0       Code
*         0      1       Heap
*         1      0        --
*         1      1       Stack
*         */

