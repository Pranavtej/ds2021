#include<stdio.h>
#include<conio.h>
void mergesort();
void merge();
int a[20];
main()
{
	int i,n;
	printf("\nEnter the size of array:");
	scanf("%d",&n);
	printf("\nEnter the elements:\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	mergesort(0,n-1);
	printf("\nAfter sorting elements are:\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	getch();
}
void    mergesort(int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		mergesort(low,mid);
		mergesort(mid+1,high);
		merge(low,mid,high);
	}
}
void merge(int low,int mid, int high)
{
	int i,j,h,k,b[20];
	h=low;
	i=low;
	j=mid+1;
	while((h<=mid)&&(j<=high))
	{
		if(a[h]<=a[j])
		{
            b[i]=a[h];
			h++;
		}
		else
		{
			b[i]=a[j];
			j++;
		}
		i++;
	}
    if (h > mid)
    {
        for (k = j; k <= high; k++)
        {
            b[i] = a[k];
            i++;
        }
    }
    else
    {
        for (k = h; k <= mid; k++)
        {
            b[i] = a[k];
            i++;
        }
    }
    for (k = low; k <= high; k++)
    {
        a[k]=b[k];
    }
}

//   for (l =j; l <= last; l++)     
//     {
//         b[k] = a[l];
//         k++;
//       }
//     }
//     else
//     {
//       for (l = i; l <= mid; l++)     
//       {
//         b[k] = a[l];
//         k++;
//       }
        
//     }