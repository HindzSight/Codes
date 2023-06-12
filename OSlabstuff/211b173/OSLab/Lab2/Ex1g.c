#include <stdio.h>
#include <stdlib.h>

struct Process {
    int pid; // Process ID
    int bt; // Burst Time
    float vr; // Virtual Runtime
};

// Function to calculate waiting time for each process
void findWaitingTime(struct Process proc[], int n, float wt[]) {
    float t = 0; // Current time
    float total_bt = 0; // Total burst time
    float min_vr = __FLT_MAX__; // Minimum virtual runtime
    int i; // Loop counter
    int j; // Loop counter

    // Calculate total burst time and minimum virtual runtime
    for (i = 0; i < n; i++) {
        total_bt += proc[i].bt;
        if (proc[i].vr < min_vr)
            min_vr = proc[i].vr;
    }

    // Keep scheduling until all processes are done
    while (1) {
        // Find the process with the minimum virtual runtime
        for (i = 0; i < n; i++) {
            if (proc[i].vr == min_vr) {
                // Execute the process for 1 unit of time
                proc[i].bt--;
                t++;
                // If the process has finished
                if (proc[i].bt == 0) {
                    wt[i] = t - total_bt; // Calculate waiting time
                    proc[i].vr = __FLT_MAX__; // Set virtual runtime to max
                }
            }
        }

        // Recalculate minimum virtual runtime
        min_vr = __FLT_MAX__;
        for (j = 0; j < n; j++) {
            if (proc[j].bt > 0 && proc[j].vr < min_vr)
                min_vr = proc[j].vr;
        }

        // If all processes have finished, break out of loop
        if (min_vr == __FLT_MAX__)
            break;
    }
}

// Function to calculate turn around time for each process
void findTurnAroundTime(struct Process proc[], int n, float wt[], float tat[]) {
    // Calculate turn around time by adding bt[i] + wt[i]
    for (int i = 0; i < n; i++)
        tat[i] = proc[i].bt + wt[i];
}

// Function to calculate average waiting time and turn around time
void findAvgTime(struct Process proc[], int n) {
    float wt[n], tat[n], total_wt = 0, total_tat = 0;

    // Calculate waiting time for each process
    findWaitingTime(proc, n, wt);

    // Calculate turn around time for each process
    findTurnAroundTime(proc, n, wt, tat);

    // Display processes along with all details
    printf("P\tBT\tVR\tWT\tTAT\n");

    // Calculate total waiting time and total turn around time
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("%d\t%d\t%.2f\t%.2f\t%.2f\n", proc[i].pid, proc[i].bt, proc[i].vr, wt[i], tat[i]);
    }

    // Calculate and display average waiting time and turn around time
    float
}
