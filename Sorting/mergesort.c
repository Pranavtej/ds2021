#include<stdio.h>
void mergesort(int[],int,int);
void merge(int[],int,int,int);
void main(void) 
{
	int a[100],i,j,temp,n;
	printf("enter the value of n");
	scanf("%d",&n);
	for(i=0;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	mergesort(a,0,n);
	printf("//---after sorting---//\n");
	for(i=0;i<=n;i++)
		{
			printf("%d\t",a[i]);
		}
}
void mergesort(int a[], int p, int r)
{
  int q;
  if(p < r)
  {
    q = (p+r)/2;
    mergesort(a, p, q);
    mergesort(a, q+1, r);
    merge(a, p, q, r);
  }
}
void merge(int a[], int p, int q, int r)
{
  int b[5];     //same size of a[]
  int i, j, k;
  k = 0;
  i = p;
  j = q+1;
  while(i <= q && j <= r)
  {
    if(a[i] < a[j])
    {
b[k++] = a[i++];       // same as b[k]=a[i]; k++; i++;
    }
    else
    {
      b[k++] = a[j++];
    }
  }
  while(i <= q)
  {
    b[k++] = a[i++];
  }
  while(j <= r)
  {
    b[k++] = a[j++];
  }
  for(i=r; i >= p; i--)
  {
    a[i] = b[--k];        // copying back the sorted list to a[]
  }
}


