#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Process {
    int pid; 
    int bt; 
    int ticket; /
};


int randomNum(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void findWaitingTime(struct Process proc[], int n, int wt[]) {
    int t = 0; // Current time
    int done = 0; 
    int total_tickets = 0; 
    int winner_ticket; 
    int winner_pid; 
    int i; // Loop counter

    for (i = 0; i < n; i++)
        total_tickets += proc[i].ticket;
    while (done < n) {
        winner_ticket = randomNum(1, total_tickets);
        for (i = 0; i < n; i++) {
    
            if (proc[i].bt > 0) {
                winner_ticket -= proc[i].ticket;
               
                if (winner_ticket <= 0) {
                    winner_pid = proc[i].pid;
                 
                    proc[i].bt--;
                 
                    if (proc[i].bt == 0) {
                        done++;
                        wt[i] = t + 1 - proc[i].ticket; // Calculate waiting time
                    }
                    break;
                }
            }
        }
        t++; 
    }
}

void findTurnAroundTime(struct Process proc[], int n, int wt[], int tat[]) {
    // Calculate turn around time by adding bt[i] + wt[i]
    for (int i = 0; i < n; i++)
        tat[i] = proc[i].bt + wt[i];
}

void findAvgTime(struct Process proc[], int n) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    findWaitingTime(proc, n, wt);

    findTurnAroundTime(proc, n, wt, tat);

    printf("P\tBT\tTicket\tWT\tTAT\n");

    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("%d\t%d\t%d\t%d\t%d\n", proc[i].pid, proc[i].bt, proc[i].ticket, wt[i], tat[i]);
    }

    float avg_wt = (float)total_wt / (float)n;
    float avg_tat = (float)total_tat / (float)n;
    printf("\nAverage Waiting Time: %f", avg_wt);
    printf("\nAverage Turnaround Time: %f\n", avg_tat);
}

int main() {
int n; 
printf("Enter the number of processes: ");
scanf("%d", &n);
truct Process proc[n]; 
srand(time(NULL)); 

for (int i = 0; i < n; i++) {
    proc[i].pid = i + 1;
    printf("Enter the burst time for process %d: ", proc[i].pid);
    scanf("%d", &proc[i].bt);
    printf("Enter the number of tickets for process %d: ", proc[i].pid);
    scanf("%d", &proc[i].ticket);
}

findAvgTime(proc, n);

return 0;
}
