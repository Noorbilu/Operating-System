#include <stdio.h>
#include <stdlib.h>

int main() {

    int t[20], n, h, i, j, temp, total = 0, d, pos;
    float avg;

    printf("Enter number of tracks: ");
    scanf("%d", &n);

    printf("Enter track positions: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }
    printf("Enter head position: ");
    scanf("%d", &h);
    t[n] = h;
    n++;
    // Sorting
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {

            if(t[i] > t[j]) {
                temp = t[i];
                t[i] = t[j];
                t[j] = temp;
            }
        }
    }
    for(i = 0; i < n; i++) {
        if(t[i] == h) {
            pos = i;
            break;
        }
    }
    for(j = pos; j < n - 1; j++) {

        d = abs(t[j + 1] - t[j]);
        total += d;

        printf("%d -> %d \t Difference: %d\n",
               t[j], t[j + 1], d);
    }
    if(pos > 0) {

        d = abs(t[n - 1] - t[pos - 1]);
        total += d;

        printf("%d -> %d \t Difference: %d\n",
               t[n - 1], t[pos - 1], d);

        for(j = pos - 1; j > 0; j--) {
            d = abs(t[j] - t[j - 1]);
            total += d;

            printf("%d -> %d \t Difference: %d\n",
                   t[j], t[j - 1], d);
        }
    }
    avg = (float) total / (n - 1);
    printf("Average head movements: %.2f\n", avg);

    return 0;
}