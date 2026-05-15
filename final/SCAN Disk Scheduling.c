#include <stdio.h>
#include <stdlib.h>

int main() {
    int t[20], n, h, pos, total = 0, curr, i, j;
    
    printf("Enter number of tracks: ");
    scanf("%d", &n);
    
    printf("Enter track positions: ");
    for(i = 0; i < n; i++) 
        scanf("%d", &t[i]);
    
    printf("Head position: ");
    scanf("%d", &h);
    
    t[n] = h;
    n++;
    
    // Sorting
    for(i = 0; i < n; i++)
        for(j = i+1; j < n; j++)
            if(t[i] > t[j]) {
                int temp = t[i];
                t[i] = t[j];
                t[j] = temp;
            }
    
    // Head er position khuje ber kora
    for(i = 0; i < n; i++)
        if(t[i] == h) pos = i;
    
    curr = pos;
    
    printf("\nSCAN Movement:\n");
    
    // Right e jawa
    for(i = pos + 1; i < n; i++) {
        int d = abs(t[i] - t[curr]);
        total += d;
        printf("%d -> %d (diff %d)\n", t[curr], t[i], d);
        curr = i;
    }
    
    // Left e jawa
    for(i = pos - 1; i >= 0; i--) {
        int d = abs(t[curr] - t[i]);
        total += d;
        printf("%d -> %d (diff %d)\n", t[curr], t[i], d);
        curr = i;
    }
    
    printf("\nAverage head movement: %.2f\n", (float)total / (n-1));
    
    return 0;
}