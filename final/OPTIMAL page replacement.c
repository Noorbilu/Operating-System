#include <stdio.h>

int main() {
    int n, m, i, j, k, pf = 0;
    int hit, pos, far, next;
    int page[50], fr[10];

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &page[i]);

    printf("Enter number of frames: ");
    scanf("%d", &m);

    for(i = 0; i < m; i++){
        fr[i] = -1;      
    }

    for(i = 0; i < n; i++) {
        hit = 0;

        // check hit
        for(j = 0; j < m; j++) {
            if(fr[j] == page[i]) {
                hit = 1;
                break;
            }
        }

        if(hit == 0) {
            pos = -1;

            // empty frame
            for(j = 0; j < m; j++) {
                if(fr[j] == -1) {
                    pos = j;
                    break;
                }
            }

            // optimal replace
            if(pos == -1) {
                far = -1;
                for(j = 0; j < m; j++) {
                    next = n + 1;
                    for(k = i + 1; k < n; k++) {
                        if(fr[j] == page[k]) {
                            next = k;
                            break;
                        }
                    }
                    if(next > far) {
                        far = next;
                        pos = j;
                    }
                }
            }

            fr[pos] = page[i];
            pf++;
        }
        for(j = 0; j < m; j++){
                printf("%d\t", fr[j]);
            }
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", pf);
    printf("Page Fault Rate: %.2f%%\n", ((float)pf / n) * 100);

    return 0;
}