#include<stdio.h>
#include<conio.h>
int largest();
void radixsort();
main()
{
	int a[20],i,n;
	printf("\nEnter the size of array:");
	scanf("%d",&n);
	printf("\nEnter the elements in array\n");
	for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
	radixsort(a,n);
	printf("\nthe sorted array\n");
	for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
	getch();
}

int largest(int a[20], int n)
{
	int large,i;
	large=a[0];
    for(i=1;i<n;i++)
    {
        if(a[i]>large)
        {
            large=a[i];
        }
    }	
	return large;
}
void radixsort(int a[20],int n)
{
	int bucket[10][20],buckcoun[20];
	int i,j,k,remainder,nop,div,large,pass;
	nop=0;
	div=1;
	large=largest(a,n);
	while(large>0)
	{
		nop++;
		large=large/10;
	}
	for(pass=0;pass<nop;pass++)
	{
		for(i=0;i<10;i++)
        {
            buckcoun[i]=0;
        }
		for(i=0;i<n;i++)
		{
			remainder=(a[i]/div)%10;
			bucket[remainder][buckcoun[remainder]]=a[i];
			buckcoun[remainder]=buckcoun[remainder]+1;
		}
		i=0;
		for(k=0;k<10;k++)
		{
			for(j=0;j<buckcoun[k];j++)
			{
				a[i]=bucket[k][j];
				i++;
			}
		}
		div=div*10;
	}
}


