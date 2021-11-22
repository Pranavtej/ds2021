#include<stdio.h>
#include<stdlib.h>
#define MAX 2
struct queue
{
    int item[MAX];
    int front,rear;
};
void insert(struct queue*,int);
int delete(struct queue*);
int peek(struct queue*);
void display(struct queue*);
int empty(struct queue*);
void main()
{
    struct queue q;
    q.rear = -1;
    q.front = 0;
    int ch,element;
    while (1)
    {
        printf("\n1.insert");
        printf("\n2.delete");
        printf("\n3.Display");
        printf("\n4.peek");
        printf("\n5.Check Stack Is empty");
        printf("\n6.Exit");
        printf("\n\nEnter your Choice :");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("Enter element to push");
            scanf("%d",&element);
            insert(&q,element);
            break;
        case 2:
            element = delete(&q);
            if(element == -1)
            {
                printf("Queue is empty");    
            }
            else
            {
                printf("%d is removed",element);
            }
            break;
        case 3:
            display(&q);
            break;
        case 4:
            element = peek(&q);
            if(element == -1)
            {
                printf("Queue is empty");    
            }
            else
            {
                printf("%d is top element",element);
            }

            break;
        case 5:
            element = empty(&q);
            if(element == 1)
            {
                printf("Queue is empty");    
            }
            else
            {
                printf("Queue contatin elements");
            }
            
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
void insert(struct queue *qu,int element)
{
    if(qu->rear == MAX-1)
    {
        printf("queue is full");
    }
    else
    {
        qu->rear = qu->rear+1;
        qu->item[qu->rear] = element;
    }
}

void display(struct queue *qu)
{
    int i;
    for(i=qu->front;i<=qu->rear;i++)
    {
        printf("\n%d indexed element is |%d|",i,qu->item[i]);
    }
}

int delete(struct queue *qu)
{
    int ele;
    if(qu->front>qu->rear)
    {
        return -1;
    }
    else
    {
        ele = qu->item[qu->front];
        qu->front = qu->front + 1;
        return ele;
    }
}
int peek (struct queue *qu)
{
    int ele;
    if(qu->front>qu->rear)
    {
        return -1;
    }
    else
    {
        ele = qu->item[qu->front];
        return ele;
    }
}

int empty(struct queue *qu)
{
     if(qu->front>qu->rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}