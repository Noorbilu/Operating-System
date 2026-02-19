
#include<stdio.h>

int main()
{
    int n, i, j, time = 0, completed = 0;
    int at[20], bt[20], wt[20], tat[20], ct[20], p[20], done[20];
    float wtavg = 0, tatavg = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\nEnter Arrival Time for process %d: ", i);
        scanf("%d", &at[i]);
        printf("Enter Burst Time for process %d: ", i);
        scanf("%d", &bt[i]);
        p[i] = i;
        done[i] = 0; // not completed
    }

    while(completed < n)
    {
        int idx = -1;
        int minBT = 9999;

        for(i = 0; i < n; i++)
        {
            if(at[i] <= time && done[i] == 0 && bt[i] < minBT)
            {
                minBT = bt[i];
                idx = i;
            }
        }

        if(idx == -1)
        {
            time++;
            continue;
        }

        time += bt[idx];
        ct[idx] = time;
        tat[idx] = ct[idx] - at[idx];
        wt[idx] = tat[idx] - bt[idx];

        wtavg += wt[idx];
        tatavg += tat[idx];

        done[idx] = 1;
        completed++;
    }

    printf("\nProcess\tAT\tBT\tWT\tTAT\n");

    for(i = 0; i < n; i++)
    {
        printf("p%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %f", wtavg / n);
    printf("Average Turnaround Time = %f\n", tatavg / n);

    return 0;
}
