#include <stdio.h>

int main() {
    int t[20], n, h, i, j, temp, total = 0, d;
    float avg;

    printf("Enter number of tracks: ");
    scanf("%d", &n);

    printf("Enter head position: ");
    scanf("%d", &h);

    printf("Enter track positions: ");
    for(i = 0; i < n; i++)
        scanf("%d", &t[i]);

    t[n] = h;
    n++;

    // sort
    for(i = 0; i < n-1; i++)
        for(j = 0; j < n-1; j++)
            if(t[j] > t[j+1]) {
                temp = t[j];
                t[j] = t[j+1];
                t[j+1] = temp;
            }

    // find head
    for(i = 0; i < n; i++)
        if(t[i] == h) break;

    printf("\nTracks\tDifference\n");

    // move right
    for(j = i; j < n-1; j++) {
        d = t[j+1] - t[j];
        total += d;
        printf("%d\t%d\n", t[j], d);
    }

    // move left
    for(j = n-1; j > 0; j--) {
        d = t[j] - t[j-1];
        total += d;
        printf("%d\t%d\n", t[j], d);
    }

    avg = (float) total / (n - 1);
    printf("\nAverage header movements: %.2f\n", avg);

    return 0;
}
