#include <stdio.h>

int main() {
    int n, time = 0, completed = 0;
    int at[20], bt[20], pr[20];
    int ct[20], tat[20], wt[20];
    int done[20] = {0};
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("\nP%d\n", i+1);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        printf("Priority (lower = higher): ");
        scanf("%d", &pr[i]);
    }

    while(completed < n) {
        int idx = -1;
        int best_pr = 9999;

        for(int i = 0; i < n; i++) {
            if(at[i] <= time && done[i] == 0) {
                if(pr[i] < best_pr) {
                    best_pr = pr[i];
                    idx = i;
                }
            }
        }

        if(idx != -1) {
            time += bt[idx];
            ct[idx] = time;
            done[idx] = 1;
            completed++;
        } else {
            time++;  // CPU idle
        }
    }

    printf("\nP\tAT\tBT\tPR\tCT\tTAT\tWT\n");

    for(int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        avg_tat += tat[i];
        avg_wt += wt[i];

        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], pr[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage TAT = %.2f", avg_tat/n);
    printf("\nAverage WT = %.2f\n", avg_wt/n);

    return 0;
}
