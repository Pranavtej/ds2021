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
    int i,j,k,div,reminder,nop,pass,larg;
    int bucket[10][20],bucketcount[10];
    div=1;
    larg = largest(a,n);
    nop= noofdigits(larg);

    printf("largest:%d\t noofdigits:%d\n",larg,nop);

    for(pass=0;pass<nop;pass++)
    {
        for(i=0;i<10;i++)
        {
            bucketcount[i]=0;
        }
        for(i=0;i<=n;i++)
        {
            reminder = (a[i]/div)%10;
            bucket[reminder][bucketcount[reminder]]=a[i];
            bucketcount[reminder]= bucketcount[reminder]+1;
        }
        i=0;
        for(k=0;k<10;k++)
        {
            for(j=0;j<bucketcount[k];j++)
            {
                a[i]=bucket[k][j];
                i++;
            }
        }
        div=div*10;
    }
}