#include <stdio.h>

int main() {
    int fr[10], page[20], n, m, i, j, k, pos, pf = 0;

    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &page[i]);

    scanf("%d", &m);

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
            pos = -1;

            for(j = 0; j < m; j++) {
                if(fr[j] == -1) {
                    pos = j;
                    break;
                }
            }

            if(pos == -1) {
                int far = -1, index = 0;

                for(j = 0; j < m; j++) {
                    int next = 999;

                    for(k = i + 1; k < n; k++) {
                        if(fr[j] == page[k]) {
                            next = k;
                            break;
                        }
                    }

                    if(next > far) {
                        far = next;
                        index = j;
                    }
                }
                pos = index;
            }

            fr[pos] = page[i];
            pf++;
        }

        for(j = 0; j < m; j++)
            printf("%d\t", fr[j]);
        printf("\n");
    }

    printf("Number of page faults: %d\n", pf);
    return 0;
}
