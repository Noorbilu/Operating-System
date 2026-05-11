#include <stdio.h>

int main() {
    int d[50] = {0}, s, l, i;

    printf("Enter starting block: ");
    scanf("%d", &s);

    printf("Enter length of file: ");
    scanf("%d", &l);

    for(i = s; i < s + l; i++) {
        if(d[i]) {
            printf("Block already allocated\n");
            return 0;
        }
    }

    printf("Blocks allocated:\n");
    for(i = s; i < s + l; i++) {
        d[i] = 1;
        printf("%d->%d\n", i, d[i]);
    }

    printf("The file is allocated to disk\n");

    return 0;
}
