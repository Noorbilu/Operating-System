#include <stdio.h>
int main()
{
    int bt[20], at[20], wt[20], tat[20], ct[20], i, n;
    float wtavg = 0, tatavg = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nProcess P%d\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
    }

    int time = 0;

    for (i = 0; i < n; i++)
    {
        if (time < at[i])
            time = at[i]; // CPU idle until process arrives

        wt[i] = time - at[i];
        time += bt[i];
        ct[i] = time;
        tat[i] = bt[i] + wt[i];

        wtavg += wt[i];
        tatavg += tat[i];
    }

    printf("\nProcess\tAT\tBT\tCT\tWT\tTAT\n");
    for (i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], wt[i], tat[i]);

    printf("\nAverage Waiting Time = %.2f\n", wtavg / n);
    printf("Average Turnaround Time = %.2f\n", tatavg / n);

    return 0;
}