#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void lru(char* s, int frame_size) {
    int n = strlen(s);

    int* frame = (int*)malloc(sizeof(int) * frame_size);
    memset(frame, -1, sizeof(int) * frame_size);
    int hit = 0;
    for (int i = 0; i < n; i++) {
        int current_value = s[i] - '0';

        int flag = 0;
        for (int j = 0; j < frame_size; j++) {
            if (frame[j] == current_value) {
                printf("Hit for value %d\n", current_value);
                flag = 1;
                hit += 1;
                break;
            }
        }
        if (flag == 1) {
            // hit condition
            continue;
        }

        int* set = (int*)malloc(sizeof(int) * frame_size);
        memset(set, -1, sizeof(int) * frame_size);
        int third_unique = -1;
        for (int j = i - 1; j >= 0; j--) {
            int temp = s[j] - '0';
            int k;
            for (k = 0; k < frame_size; k++) {
                if (set[k] == temp) {
                    break;
                }
            }
            if (k == frame_size) {
                for (k = 0; k < frame_size; k++) {
                    if (frame[k] == set[0]) {
                        frame[k] = temp;
                        break;
                    }
                }
                if (k == frame_size) {
                    frame[0] = temp;
                }
                third_unique = temp;
                break;
            }
            set[k] = temp;
        }

        if (third_unique == -1) {
            int j;
            for (j = 0; j < frame_size; j++) {
                if (frame[j] == -1) {
                    frame[j] = current_value;
                    break;
                }
            }
            if (j == frame_size) {
                for (j = 0; j < frame_size - 1; j++) {
                    frame[j] = frame[j + 1];
                }
                frame[j] = current_value;
            }
        }
        free(set);

        printf("Frame:: ");
        for (int j = 0; j < frame_size; j++) {
            printf("%d ", frame[j]);
        }
        printf("\n");
    }
    printf("Page Fault : %d\n", n - hit);

    free(frame);
}

int main() {
    char ref_string[MAX_SIZE];
    int n;

    printf("Enter the reference string:\n");
    scanf("%s", ref_string);
    printf("Enter the frame number:\n");
    scanf("%d", &n);

    lru(ref_string, n);

    return 0;
}
