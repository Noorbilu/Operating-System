#include <stdio.h>

int fr[3];

void display()
{
    int i;
    for(i = 0; i < 3; i++)
        printf("%d\t", fr[i]);
    printf("\n");
}

int main()
{
    int page[12] = {2,3,2,1,5,2,4,5,3,2,5,2};
    int i, j, k = 0, pf = 0;

    for(i = 0; i < 3; i++)
        fr[i] = -1;

    for(j = 0; j < 12; j++)
    {
        int flag = 0;

        for(i = 0; i < 3; i++)
            if(fr[i] == page[j]) flag = 1;

        if(flag == 0)
        {
            fr[k] = page[j];
            k = (k + 1) % 3;
            pf++;
        }

        display();
    }

    printf("\nNumber of page faults: %d\n", pf + 3);

    return 0;
}
