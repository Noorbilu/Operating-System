#include <stdio.h>

int main() {
    int d[50] = {0}, i, n, idx, b[50];

    printf("Enter index block: ");
    scanf("%d", &idx);

    if(d[idx]) {
        printf("Index block already allocated\n");
        return 0;
    }

    printf("Enter number of blocks: ");
    scanf("%d", &n);

    printf("Enter block numbers: ");
    for(i = 0; i < n; i++)
        scanf("%d", &b[i]);

    for(i = 0; i < n; i++)
        if(d[b[i]]) {
            printf("Block already allocated\n");
            return 0;
        }

    d[idx] = 1;
    for(i = 0; i < n; i++)
        d[b[i]] = 1;

    printf("\nFile Allocation:\n");
    for(i = 0; i < n; i++)
        printf("%d->%d\n", idx, b[i]);

    return 0;
}
