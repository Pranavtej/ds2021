#include<stdio.h>
#include<conio.h>
void main()
{
    int n,i;
    int arr[10];
    int k;
    printf("Enter array length");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter Element to search");
    scanf("%d",&k);
    for(i=0;i<n;i++)
    {
        if(arr[i] == k)
        {
            printf("Element is found in %d",i+1);
            break;
        }
    }
    if (i==n)
    {
        printf("Element is not found in list");
    }
    getch();
}
    