#include<stdio.h>
#define MAX 10
struct queue
{
    int items[MAX];
    int rear,front;
};
void insert(struct queue*,int);
void display(struct queue*);
int delete(struct queue*);
int peek(struct queue*);
int empty(struct queue*);


void main()
{
    struct queue q;
    q.rear = -1;
    q.front = 0;
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
                printf("%d is first element",element);
            }
            break;
        case 5:
            element = empty(&q);
            if(element == 0)
            {
                printf("Queue is empty");
            }
            else
            {
                printf("Queue contain elements");
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
void insert(struct queue *qu,int el)
{
    if(qu->rear == MAX-1)
    {
        printf("queue is full");
    }
    else
    {
        qu->rear =qu->rear +1;
        qu->items[qu->rear] = el;
        printf("Element inserted %d",el);
    }
}
void display(struct queue *qu)
{
    int i;

    for(i=qu->front;i<=qu->rear;i++)
    {
        printf("\n%d indexed value is |%d|",i,qu->items[i]);
    }
}

int delete(struct queue *qu)
{
    int el;
    if(qu->rear<qu->front)
    {
        return -1;
    }
    else
    {
        el = qu->items[qu->front];
        qu->front = qu->front+1;
        return el;
    }
}
int peek(struct queue *qu)
{
    int el;
    if(qu->rear<qu->front)
    {
        return -1;
    }
    else
    {
        el = qu->items[qu->front];
        return el;
    }
}

int empty(struct queue *qu)
{
    int el;
    if(qu->rear<qu->front)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}


