#include <stdio.h>
#define MAX 20

int main() {
    int n, tq;
    int at[MAX], bt[MAX], rt[MAX];      // arrival, burst, remaining
    int ct[MAX], tat[MAX], wt[MAX];     // completion, turnaround, waiting
    int q[MAX], front = 0, rear = 0;    // ready queue
    int visited[MAX] = {0};             // একবার queue-তে গেছে কি না

    int time = 0, completed = 0;
    float sumWT = 0, sumTAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nProcess P%d\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        rt[i] = bt[i];      // শুরুতে remaining = burst
    }

    printf("\nEnter Time Quantum: ");
    scanf("%d", &tq);

    time = 0;     // time = 0 এ যে সব process এসে গেছে, তাদের queue-তে দিই
    for (int i = 0; i < n; i++) {
        if (at[i] <= time && visited[i] == 0) {
            q[rear++] = i;
            visited[i] = 1;
        }
    }

    while (completed < n) { // Round Robin simulation

        if (front == rear) {        // ready queue ফাঁকা → CPU idle → time বাড়াই, নতুন arrival ধরে নেই
            time++;
            for (int i = 0; i < n; i++) {
                if (at[i] <= time && visited[i] == 0) {
                    q[rear++] = i;
                    visited[i] = 1;
                }
            }
            continue;
        }

        int idx = q[front++];         // queue-এর প্রথম process-টা নেই

        if (rt[idx] > tq) {        // queue-এর প্রথম process-টা নেই
            time   += tq;
            rt[idx] -= tq;
        } else {
            time    += rt[idx];
            rt[idx]  = 0;
            ct[idx]  = time;   // finish time
            completed++;
        }

        for (int j = 0; j < n; j++) {        // এই সময়ের মধ্যে যে সব নতুন process এসে গেছে, তাদের আগে queue-তে দিই
            if (at[j] <= time && visited[j] == 0) {
                q[rear++] = j;
                visited[j] = 1;
            }
        }

        if (rt[idx] > 0) {         // যদি কাজ বাকি থাকে, তখনই আবার queue-র শেষে পাঠাই
            q[rear++] = idx;
        }
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];     // TAT = CT - AT
        wt[i]  = tat[i] - bt[i];    // WT  = TAT - BT

        sumWT  += wt[i];
        sumTAT += tat[i];

        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time = %.2f", sumTAT / n);
    printf("\nAverage Waiting Time    = %.2f\n", sumWT / n);

    return 0;
}
