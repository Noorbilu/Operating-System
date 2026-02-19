#include <stdio.h>

#define MAX 20

int main() {
    int n, tq;
    int at[MAX], bt[MAX], rt[MAX];
    int ct[MAX], tat[MAX], wt[MAX];

    int queue[MAX], front = 0, rear = 0;
    int visited[MAX] = {0};

    int time = 0, completed = 0;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("\nProcess P%d\n", i+1);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    printf("\nEnter Time Quantum: ");
    scanf("%d", &tq);

    // Start from first arrival time
    time = 0;

    // Add processes that arrive at time 0
    for(int i = 0; i < n; i++) {
        if(at[i] <= time && visited[i] == 0) {
            queue[rear++] = i;
            visited[i] = 1;
        }
    }

    printf("\nGantt Chart:\n");

    while(completed < n) {

        if(front == rear) {
            time++;
            for(int i = 0; i < n; i++) {
                if(at[i] <= time && visited[i] == 0) {
                    queue[rear++] = i;
                    visited[i] = 1;
                }
            }
            continue;
        }

        int i = queue[front++];

        if(rt[i] > tq) {
            printf("| P%d (%d-%d) ", i+1, time, time+tq);
            time += tq;
            rt[i] -= tq;
        }
        else {
            printf("| P%d (%d-%d) ", i+1, time, time+rt[i]);
            time += rt[i];
            ct[i] = time;
            rt[i] = 0;
            completed++;
        }

        // Add newly arrived processes to queue
        for(int j = 0; j < n; j++) {
            if(at[j] <= time && visited[j] == 0) {
                queue[rear++] = j;
                visited[j] = 1;
            }
        }

        // If process not finished, push back to queue
        if(rt[i] > 0) {
            queue[rear++] = i;
        }
    }

    printf("|\n");

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for(int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        avg_wt += wt[i];
        avg_tat += tat[i];

        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time = %.2f", avg_tat/n);
    printf("\nAverage Waiting Time = %.2f\n", avg_wt/n);

    return 0;
}
