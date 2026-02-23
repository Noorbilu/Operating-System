#include <stdio.h>

int main() {
    int n, i,time = 0, done = 0;
    int at[20], bt[20], rt[20], wt[20], tat[20], ct[20];  
    float sumWT = 0, sumTAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter AT and BT for P%d: ", i);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    while (done < n) {
        int idx = -1, minRT = 1000000;

        for (i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0 && rt[i] < minRT) {
                minRT = rt[i];
                idx = i;
            }
        }

        if (idx == -1) {
            time++;
            continue;
        }

        rt[idx]--;
        time++;

        if (rt[idx] == 0) {
            done++;
            ct[idx]  = time;             
            tat[idx] = time - at[idx];
            wt[idx]  = tat[idx] - bt[idx];
            sumWT   += wt[idx];
            sumTAT  += tat[idx];
        }
    }

    printf("\nP\tAT\tBT\tCT\tWT\tTAT\n");  
    for (i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i, at[i], bt[i], ct[i], wt[i], tat[i]);  // ct[i] print

    printf("\nAverage Waiting Time   = %.2f", sumWT / n);
    printf("\nAverage Turnaround Time = %.2f\n", sumTAT / n);

    return 0;
}
