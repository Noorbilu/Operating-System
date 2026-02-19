#include <stdio.h>

int main() {
    int n, r;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &r);

    int alloc[n][r], max[n][r], need[n][r];
    int total[r], available[r];
    int finish[n];
    int safeSeq[n];

    // Input Allocation matrix
    printf("\nEnter Allocation Matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < r; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    // Input Max matrix
    printf("\nEnter Max Matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < r; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    // Input Total Resources
    printf("\nEnter Total Resources:\n");
    for(int i = 0; i < r; i++) {
        scanf("%d", &total[i]);
    }

    // Calculate Available
    for(int i = 0; i < r; i++) {
        int sum = 0;
        for(int j = 0; j < n; j++) {
            sum += alloc[j][i];
        }
        available[i] = total[i] - sum;
    }

    // Calculate Need = Max - Allocation
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < r; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    // Print Need Matrix
    printf("\nNeed Matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < r; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    // Print Available Resources
    printf("\nAvailable Resources:\n");
    for(int i = 0; i < r; i++) {
        printf("%d ", available[i]);
    }
    printf("\n");

    // Initialize finish
    for(int i = 0; i < n; i++) {
        finish[i] = 0;
    }

    int count = 0;

    while(count < n) {
        int found = 0;

        for(int i = 0; i < n; i++) {
            if(finish[i] == 0) {
                int flag = 1;

                for(int j = 0; j < r; j++) {
                    if(need[i][j] > available[j]) {
                        flag = 0;
                        break;
                    }
                }

                if(flag) {
                    for(int j = 0; j < r; j++) {
                        available[j] += alloc[i][j];
                    }

                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0) {
            break;
        }
    }

    if(count == n) {
        printf("\nSystem is in SAFE state.\nSafe sequence: ");
        for(int i = 0; i < n; i++) {
            printf("P%d ", safeSeq[i]);
        }
        printf("\n");
    } else {
        printf("\nSystem is NOT in safe state (Deadlock possible).\n");
    }

    return 0;
}
