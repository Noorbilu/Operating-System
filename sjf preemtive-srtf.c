
#include<stdio.h>

int main()
{
    int bt[20], at[20], rt[20], wt[20], tat[20], ct[20];
    int i, n, time = 0, count = 0, smallest;
    float wtavg = 0, tatavg = 0;

    printf("\nEnter the number of process: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\nEnter Arrival Time for process %d: ", i);
        scanf("%d", &at[i]);
        printf("Enter Burst Time for process %d: ", i);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];   // remaining time = burst time
    }

    while(count < n)
    {
        smallest = -1;

        for(i = 0; i < n; i++)
        {
            if(at[i] <= time && rt[i] > 0)
            {
                if(smallest == -1 || rt[i] < rt[smallest])
                {
                    smallest = i;
                }
            }
        }

        time++;

        if(smallest != -1)
        {
            rt[smallest]--;

            if(rt[smallest] == 0)
            {
                count++;
                ct[smallest] = time;
                tat[smallest] = ct[smallest] - at[smallest];
                wt[smallest] = tat[smallest] - bt[smallest];

                wtavg += wt[smallest];
                tatavg += tat[smallest];
            }
        }
    }

    printf("\n\tProcess\tAT\tBT\tWT\tTAT\n");

    for(i = 0; i < n; i++)
    {
        printf("\n\tp%d\t%d\t%d\t%d\t%d", i, at[i], bt[i], wt[i], tat[i]);
    }

    printf("\n\nAverage Waiting Time : %f", wtavg / n);
    printf("\nAverage Turnaround Time : %f", tatavg / n);

    return 0;
}
