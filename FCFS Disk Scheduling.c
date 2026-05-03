#include <stdio.h>

int main() {
    int t[20], n, i, diff, total = 0;
    float avg;

    printf("Enter number of tracks: ");
    scanf("%d", &n);

    printf("Enter track positions: ");
    for(i = 0; i < n; i++)
        scanf("%d", &t[i]);

    printf("\nTracks traversed\n");

    for(i = 0; i < n - 1; i++) {
        diff = t[i+1] - t[i];
        if(diff < 0) diff = -diff;

        total += diff;
        printf("%d\n", t[i]);
    }

    printf("%d\n", t[n-1]);

    avg = (float) total / (n - 1);
    printf("\nAverage header movements: %.2f\n", avg);

    return 0;
}
