#include<stdio.h>
#include<conio.h>
int get_fibonacci(int);

int fibonacci_Search(int A[], int n, int key)
{
	int low = 0;
    int high = n-1; 
    int loc = -1; 
    int flag = 0;
    int index = 0;
	while ((flag != 1) && (low <= high))
	{
		//get Fibonacci number < n
		index = get_fibonacci(n);

		printf("---------\n");
		printf("low\thigh\tloc\tflag\tindex\tn\n");
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",low,high,loc,flag,index,n);
		printf("---------\n");

		if (key == A[index + low]) 
		{
			flag = 1; 
			loc = index + low;
			break;
		}
		else if (key > A[index + low])
        {
            low = low + index + 1;
        }
		else 
		{
			high = low + index-1;
		}
		n = high - low +1;
	}
	if(flag==1)
	{
    	return loc;
	}
	else
	{
		return -1;
	}
}

int get_fibonacci(int n)
{
	int fibk2= 0;
  	int fibk1= 1;
  	int fibk= 0;
    if ( n == 0 || n == 1) 
	{
  		return 0;
	}
    while(fibk<n)
    { 
               fibk = fibk2 + fibk1;
               fibk2 = fibk1;
               fibk1 = fibk;
    }
     return fibk2;
}

void main()
{
    int n,i;
    int arr[10];
    int k;
    int res;
    printf("Enter array length");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter Element to search");
    scanf("%d",&k);
     
    res = fibonacci_Search(arr,n,k);
    if(res == -1)
    {
        printf("Element not found");
    }
    else
    {
        printf("Element is found at %d",res);
    }
    getch();
}
