#include<stdio.h>
int main()
{
    int i, a[19], j, k, small, s;

    printf("enter 10 elements ");
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < 10; i++)
    {
        small = i;
        for (j = i + 1; j < 10; j++)
        {
            if (a[j] < a[small])
            {
                small = j;
                k = j;
            }
            s - a[i];
            a[i] = a[k];
            a[k] = s;
        }
        for (i = 0; i < 10; i++)
        {
            printf("%d\t", a[i]);
        }
    }
}