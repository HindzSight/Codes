#include<stdio.h>

int main()
{
    float v_add;
    float base;
    printf("Enter the Virtual Address to be relocated(in Bytes): ");
    scanf("%f", &v_add);
    printf("Enter the base Address of the block(in KB) : ");
    scanf("%f", &base);

    /*
     * code 0 to 4 KB
     * heap 4KB to 8KB
     * stack 16KB to 12KB
     */

    if(v_add > 0 && v_add < 2*1024)
    {
        float offset;
        offset = v_add;
        if(offset > 2*1024 )
        {
            printf("Segmentation fault\n");
        }
        else
        {
            float p_add = base*1024 + offset;
            printf("Physical Address : (in B) %f\n", p_add);
        }
    }
    else if(v_add > 4*1024 && v_add < 7*1024)
    {
        float offset;
        offset = v_add - 4*1024;

        if(offset > 4*1024 )
        {
            printf("Segmentation fault\n");
        }
        else
        {
            float p_add = base*1024 + offset;
            printf("Physical Address : (in B) %f\n", p_add);
        }
    }
    else if(v_add > 14*1024 && v_add < 16*1024)
    {
        float offset;
        offset = v_add - 16*1024;

        if(offset > 14*1024 )
        {
            printf("Segmentation fault\n");
        }
        else
        {
            float p_add = base*1024 + offset;
            printf("Physical Address : (in B) %f\n", p_add);
        }
    }
    else
    {
        printf("Segmentation Fault\n");
    }

    return 0;
}

