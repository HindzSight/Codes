#include <stdio.h>
#include <limits.h>
#include <string.h>

void oprp(char s[], int frame_size)
{
    int n = strlen(s);
    int hit_count = 0;
    int frame[frame_size];
    int frame_index = 0;

    for (int i = 0; i < n; i++)
    {
        int current_value = s[i] - '0';

        int flag = 0;
        for (int j = 0; j < frame_index; j++)
        {
            if (frame[j] == current_value)
            {
                printf("Hit for value %d\n", current_value);
                hit_count++;
                flag = 1;
                break;
            }
        }

        if (flag == 1)
        {
            // hit condition
            continue;
        }

        if (frame_index < frame_size)
        {
            frame[frame_index] = current_value;
            frame_index++;
        }
        else
        {
            int index[frame_size];
            int flag2 = 0;
            for (int k = 0; k < frame_size; k++)
            {
                int ele = frame[k];
                int ele_index = INT_MAX;
                flag2 = 0;
                for (int j = i + 1; j < n; j++)
                {
                    int temp1 = s[j] - '0';
                    if (temp1 == ele)
                    {
                        index[k] = j;
                        flag2 = 1;
                        break;
                    }
                }
                if (flag2 == 0)
                {
                    index[k] = INT_MAX;
                }
            }

            int maximum_index = -1;
            int maximum_index_value = -1;
            for (int j = 0; j < frame_size; j++)
            {
                if (index[j] > maximum_index_value)
                {
                    maximum_index_value = index[j];
                    maximum_index = j;
                }
            }

            int ele1 = s[maximum_index] - '0';
            frame[maximum_index] = current_value;
        }

        printf("Frame:: ");
        for (int j = 0; j < frame_index; j++)
        {
            printf("%d ", frame[j]);
        }
        printf("\n");
    }
    printf("\nPage Fault:: %d\n", n - hit_count);
}

int main()
{
    int n;
    char ref_string[100];
    printf("Enter the reference string\n");
    scanf("%s", ref_string);
    printf("Enter the frame number\n");
    scanf("%d", &n);

    oprp(ref_string, n);

    return 0;
}
