#include<stdio.h>
#include<stdlib.h>
#define MAX 4
struct cqueue
{
    int items[MAX];
    int rear,front;
};
void enque(struct cqueue*,int);
void display(struct cqueue*);
int del(struct cqueue*);


void main()
{
    struct cqueue q;
    q.rear = -1;
    q.front = -1;
    int ch,element;
    while (1)
    {
        printf("\n1.insert/enqueue");
        printf("\n2.delete/Dequeue");
        printf("\n3.Display");
        printf("\n4.peek");
        printf("\n5.Check Stack Is empty");
        printf("\n6.Exit");
        printf("\n\nEnter your Choice :");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("Enter element");
            scanf("%d",&element);
            enque(&q,element);
            break;
        case 2:
            element=del(&q);
			if(element==-1)
				printf("\nqueue is empty");
			else
				printf("\ndeleted element is %d",element);
			printf("\nelements are:");
			display(&q);

            break;
        case 3:
            display(&q);
            break;
        case 4:
            printf("Delete");
            break;
        case 5:
            printf("Empty");
            break;            
        case 6:
            exit(0);
            break;
        default:
            printf("invalid choice");
            break;
        }
    }
    
}

void enque(struct cqueue *cqu,int element)
{
    if(((cqu->front == 0) && (cqu->rear == MAX-1))||(cqu->front==cqu->rear+1))
    {
        printf("Circle queue is full");
    }
    if(cqu->front == -1)
    {
        cqu->front=0;
        cqu->rear=0;
    }
    else
    {
        if(cqu->rear == MAX-1)
        {
            cqu->rear = 0;
        }
        else
        {
            cqu->rear =cqu->rear+1;
        }

    }
    cqu->items[cqu->rear] = element;
}
void display(struct cqueue *cqu)
{
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
            for(i=cqu->front;i<=MAX-1;i++)
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
		if(cqu->front==MAX-1)
			cqu->front=0;
		else
			cqu->front++;
	}
	return a;
}
