#include <stdio.h>
void radix(int[],int);
void main(void) 
{
	int a[20],i,n;
	printf("enter the value of n");
	scanf("%d",&n);
	for(i=0;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	radix(a,n);
	printf("//---after sorting---//\n");
	for(i=0;i<=n;i++)
	{
		printf("%d\t",a[i]);
	 }
}
int largest(int a[],int n)
{
    int largest,i;
    largest = a[0];
    for(i=1;i<=n;i++)
    {
        if(a[i]>largest)
        {
            largest = a[i];
        }
    }
    return largest;
}
int noofdigits(int n)
{
    int digits=0;
    while(n>0)
    {
        digits++;
        n=n/10;
    }
    return digits;
}

void radix(int a[],int n)
{
    int i,j,k,d=1,r,l,nop,pass;
    int bucket[10][20],bc[10];
    l=largest(a,n);
    nop=noofdigits(l);
    for(pass=0;pass<nop;pass++)
    {
        for(i=0;i<10;i++)
        {
            bc[i]=0;
        } 
        for(i=0;i<=n;i++)
        {
            r=(a[i]/d)%10;
            bucket[r][bc[r]]=a[i];
            bc[r]+=1;
        }
        i=0;
        for(k=0;k<10;k++)
        {
            for(j=0;j<bc[k];j++)
            {
                a[i]=bucket[k][j];
                i++;
            }
        }
        d*=10;

    }
}
