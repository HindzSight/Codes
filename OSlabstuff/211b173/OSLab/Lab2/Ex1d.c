#include <stdio.h>
#include <stdbool.h>

struct Process {
    int pid; 
    int bt; 
    int art; 
};

void findWaitingTime(struct Process proc[], int n, int wt[], int quantum) {
    int rt[n];

    for (int i = 0; i < n; i++)
        rt[i] = proc[i].bt;

    int t = 0; // Current time
    bool check = false;

    while (true) {
        bool done = true;

        for (int i = 0; i < n; i++) {
 
            if (rt[i] > 0) {
                done = false;

                if (proc[i].art <= t) {
                    check = true;

                    if (rt[i] <= quantum) {
                        t += rt[i];
                        rt[i] = 0;
                        wt[i] = t - proc[i].bt - proc[i].art;

                        if (wt[i] < 0)
                            wt[i] = 0;
                    } 
      
                    else {
                        rt[i] -= quantum;
                        t += quantum;
                    }
                }

                else if (check == false) {
                    t++;
                }
            }
        }


        if (done == true)
            break;
    }
}


void findTurnAroundTime(struct Process proc[], int n, int wt[], int tat[]) {

    for (int i = 0; i < n; i++)
        tat[i] = proc[i].bt + wt[i];
}

void findAvgTime(struct Process proc[], int n, int quantum) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    findWaitingTime(proc, n, wt, quantum);

    findTurnAroundTime(proc, n, wt, tat);

    printf("P\tBT\tWT\tTAT\n");

    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("%d\t%d\t%d\t%d\n", proc[i].pid, proc[i].bt, wt[i], tat[i]);
    }

    float avg_wt = (float)total_wt / (float)n;
    float avg_tat = (float)total_tat / (float)n;
    printf("\nAverage Waiting Time: %f", avg_wt);
    printf("\nAverage Turnaround Time: %f\n", avg_tat);
}

int main() {
    int n, quantum;
	printf("Enter the number of processes: ");
scanf("%d", &n);

struct Process proc[n];

for (int i = 0; i < n; i++) {
    printf("\nEnter details for process %d\n", i+1);
    printf("Enter process ID: ");
    scanf("%d", &proc[i].pid);
    printf("Enter burst time: ");
    scanf("%d", &proc[i].bt);
    printf("Enter arrival time: ");
    scanf("%d", &proc[i].art);
}

printf("\nEnter time quantum: ");
scanf("%d", &quantum);

findAvgTime(proc, n, quantum);

return 0;
}
