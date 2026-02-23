#include <stdio.h>

int main() {
    int n, r, i, j;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &r);

    int alloc[n][r], max[n][r], need[n][r];
    int total[r], avail[r], finish[n], safe[n];

    // Allocation
    printf("\nEnter Allocation Matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<r;j++)
            scanf("%d",&alloc[i][j]);

    // Max
    printf("\nEnter Max Matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<r;j++)
            scanf("%d",&max[i][j]);

    // Total
    printf("\nEnter Total Resources:\n");
    for(i=0;i<r;i++)
        scanf("%d",&total[i]);

    // Available
    for(i=0;i<r;i++){
        int sum=0;
        for(j=0;j<n;j++)
            sum+=alloc[j][i];
        avail[i]=total[i]-sum;
    }

    // Need
    for(i=0;i<n;i++)
        for(j=0;j<r;j++)
            need[i][j]=max[i][j]-alloc[i][j];

    // Print Need
    printf("\nNeed Matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<r;j++)
            printf("%d ",need[i][j]);
        printf("\n");
    }

    // Print Available
    printf("\nAvailable Resources:\n");
    for(i=0;i<r;i++)
        printf("%d ",avail[i]);
    printf("\n");

    for(i=0;i<n;i++)
        finish[i]=0;

    int count=0;

    for(int k=0;k<n;k++){
        for(i=0;i<n;i++){
            if(!finish[i]){
                int ok=1;
                for(j=0;j<r;j++)
                    if(need[i][j]>avail[j])
                        ok=0;

                if(ok){
                    for(j=0;j<r;j++)
                        avail[j]+=alloc[i][j];

                    safe[count++]=i;
                    finish[i]=1;
                }
            }
        }
    }

    if(count==n){
        printf("\nSystem is in SAFE state.\n");
        printf("Safe sequence: ");
        for(i=0;i<n;i++)
            printf("P%d ",safe[i]);
    }
    else{
        printf("\nSystem is NOT in safe state (Deadlock possible).\n");
    }

    return 0;
}
