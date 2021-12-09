#include <stdio.h>
#include <conio.h>
void bubblesort(int[],int);
void selectionsort(int[],int);
void insertionsort(int[],int);
int main(void) 
{
	int a[10],i,j,temp,n;
	printf("enter the value of n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	bubblesort(a,n);
	printf("//---after sorting---//\n");
	for(i=0;i<n;i++)
		{
			printf("%d\t",a[i]);
		}
	return 0;
}
void bubblesort(int a[],int n)
{
	int i,j,temp;
	for(i=0;i<n;i++)
		{
			for(j=0;j<n-1-i;j++)
			{
				if(a[j+1]<a[j])
				{
					temp=a[j];
                    a[j]=a[j+1];
					a[j+1]=temp;
				}
			}
		}
}
void selectionsort(int a[],int n)
{
    int min=0,i,j,temp;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
        }
        temp=a[i];
        a[i]=a[min];
        a[min]=temp; 
    }
}
void insertionsort(int a[],int n)
{
	int t,i,j;
	for(i=1;i<n;i++)
	{
		t=a[i];
		for(j=i-1;j>=0;j--)
		{
			if(a[j]>t)
			{
				a[j+1]=a[j];
			}
			else
			{
				break;
			}
		}
		a[j+1]=t;
	}
}

