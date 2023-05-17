#include <stdio.h>

int main() {
    int num_processes, burst_time[50], wait_time[50], turnaround_time[50], i;
    float avg_wait_time = 0, avg_turnaround_time = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

   
    printf("Enter burst time of each process:\n");
    for (i = 0; i < num_processes; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }

    
    wait_time[0] = 0;
    for (i = 1; i < num_processes; i++) {
        wait_time[i] = wait_time[i - 1] + burst_time[i - 1];
        avg_wait_time += wait_time[i];
    }

   
    for (i = 0; i < num_processes; i++) {
        turnaround_time[i] = wait_time[i] + burst_time[i];
        avg_turnaround_time += turnaround_time[i];
    }

  
    avg_wait_time /= num_processes;
    avg_turnaround_time /= num_processes;

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < num_processes; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, burst_time[i], wait_time[i], turnaround_time[i]);
    }
    printf("\nAverage Waiting Time: %.2f", avg_wait_time);
    printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround_time);

    return 0;
}

