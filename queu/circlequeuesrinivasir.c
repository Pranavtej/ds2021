#define max 4
#include<stdio.h>
#include<stdlib.h>
struct cqueue
{
	int front,rear;
	int items[max];
};
void insert();
int del();
int empty();
int peek();
void display();
main()
{
	int choice,x;
	struct cqueue cq;
	cq.front=cq.rear=-1;
	while(1)
	{
	printf("\n\n***************************\n\n");
	printf("\t\tMENU\n");
    printf("\n***************************\n");
	printf("1.insert\n2.delete\n3.peek\n4.Empty\n5.Display\n6.exit\n");
	printf("Enter your choice:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:printf("\nEnter the element:");
			scanf("%d",&x);
			insert(&cq,x);
			printf("\nElements are:");
			display(&cq);
			break;
		case 2:	x=del(&cq);
			if(x==-1)
				printf("\nqueue is empty");
			else
				printf("\ndeleted element is %d",x);
			printf("\nelements are:");
			display(&cq);
			break;
		case 3: x=peek(&cq);
			if(x==-1)
				printf("\nCircular queue is empty");
			else
				printf("\nfirst element in Circular queue is:%d",x);
			break;
		case 4:	x=empty(&cq);
			if(x==1)
				printf("\nqueue is empty");
			else
				printf("\nqueue is not empty");
			break;
		case 5:	printf("\nElements are\n");
			display(&cq);
			break;
		case 6:	exit(0);
	}
	}
}
void insert(struct cqueue *cqu,int a)
{
	if(((cqu->front==0)&&(cqu->rear==max-1))||(cqu->front==cqu->rear+1))
	{
        printf("\nCircular queue is Overflow");
		return;
	}
	else if(cqu->front==-1)
	{
		cqu->front=0;
		cqu->rear=0;
	}
	else
	{
		if(cqu->rear==max-1)
			cqu->rear=0;
		else
			cqu->rear=cqu->rear+1;
	}
	cqu->items[cqu->rear]=a;
}
int del(struct cqueue *cqu)
{
	int a;
	if(cqu->front==-1)
	{
		return -1;
	}

	a=cqu->items[cqu->front];
	if(cqu->front==cqu->rear)
	{
		cqu->front=-1;
		cqu->rear=-1;
	}
	else
	{
		if(cqu->front==max-1)
			cqu->front=0;
		else
			cqu->front++;
	}
	return a;
}
void display(struct cqueue *cqu)
{
	// int i,j;
	// i=cqu->front;
	// j=cqu->rear;
	// if(cqu->front==-1)
    // printf("Circular Queue is Empty");
	// else
	// {
	// 	if(i<=j)
	// 		while(i<=j)
	// 		{
	// 			printf("%d\t",cqu->items[i]);
	// 			i++;
	// 		}
	// 	else
	// 	{
	// 		while(i<=max-1)
	// 		{
	// 			printf("%d\t",cqu->items[i]);
	// 			i++;
	// 		}
	// 		i=0;
	// 		while(i<=j)
	// 		{
	// 			printf("%d\t",cqu->items[i]);
	// 			i++;
	// 		}
	// 	}
	// }
     int i;
    if(cqu->front == -1)
    {
        printf("Circle queue is empty");
    }
    else
    {
        if(cqu->front <= cqu->rear)
        {
            for(i=cqu->front;i<=cqu->rear;i++)
            {
                printf("\n%d indexed element is |%d|",i,cqu->items[i]);
            }
        }
        else
        {
            for(i=cqu->front;i<=max-1;i++)
            {
                printf("\n%d indexed element is |%d|",i,cqu->items[i]);
            }
            for(i=0;i<=cqu->rear;i++)
            {
                printf("\n%d indexed element is |%d|",i,cqu->items[i]);
            }
        }
    }

}
int empty(struct  cqueue *cqu)
{
	int b;
	if(cqu->front==-1)
		return 1;
	else
		return 0;
}
int peek(struct  cqueue *cqu)
{
	int b;
	if(cqu->front==-1)
		return -1;
	else
		return cqu->items[cqu->front];
}



