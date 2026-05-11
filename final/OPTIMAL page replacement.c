#include <stdio.h>

int main() {
    int n, m, i, j, k, pf = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    int page[n];

    printf("Enter reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &page[i]);

    printf("Enter number of frames: ");
    scanf("%d", &m);

    int fr[m];

    for(i = 0; i < m; i++)
        fr[i] = -1;

    for(i = 0; i < n; i++) {

        int found = 0;

        for(j = 0; j < m; j++) {
            if(fr[j] == page[i]) {
                found = 1;
                break;
            }
        }

        if(found == 0) {

            int pos = -1;

            // Empty frame check
            for(j = 0; j < m; j++) {
                if(fr[j] == -1) {
                    pos = j;
                    break;
                }
            }

            // Optimal replacement
            if(pos == -1) {

                int far = -1;

                for(j = 0; j < m; j++) {

                    int next_use = 999;

                    for(k = i + 1; k < n; k++) {
                        if(fr[j] == page[k]) {
                            next_use = k;
                            break;
                        }
                    }

                    if(next_use > far) {
                        far = next_use;
                        pos = j;
                    }
                }
            }

            fr[pos] = page[i];
            pf++;
        }

        for(j = 0; j < m; j++)
            printf("%d\t", fr[j]);

        printf("\n");
    }

    float rate = ((float)pf / n) * 100;

    printf("\nTotal Page Faults: %d\n", pf);
    printf("Page Fault Rate: %.2f%%\n", rate);

    return 0;
}