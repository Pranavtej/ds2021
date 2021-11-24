#include<stdio.h>
#define MAX 4
struct queue 
{
    int items[MAX];
    int front,rear;
};
void enque(struct queue*,int);
void display(struct queue*);
int dequeu(struct queue*);
int peek(struct queue*);
int empty(struct queue*);
void main()
{
    struct queue q;
    q.front = 0;
    q.rear =-1;
    int element;
    int ch;
    while (1)
    {
        printf("\n1.insert/enqueue");
        printf("\n2.delete/Dequeue");
        printf("\n3.Display");
        printf("\n4.peek");
        printf("\n5.Check queue Is empty");
        printf("\n6.Exit");
        printf("\n\nEnter your Choice :");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("Enter element to insert");
            scanf("%d",&element);
            enque(&q,element);
            break;
        case 2:
            element = dequeu(&q);
            if(element ==  -1)
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
            if(element ==  -1)
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
            if(element == -1)
            {
                printf("Queue is empty");
            }
            else
            {
                printf("Queue contatins elements");
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

void enque(struct queue *qu,int el)
{
    if(qu->rear == MAX-1)
    {
        printf("Queue is full");
    }
    else
    {
        qu->rear =qu->rear +1;
        qu->items[qu->rear] =el;
        printf("%d is inserted",el);
    }

}
void display(struct queue *qu)
{
    int i;
    if(qu->rear< qu->front)
    {
        printf("Queue is empty");

    }
    else
    {
        for(i=qu->front;i<=qu->rear;i++)
        {
            printf("\n%d indexed value is |%d|",i,qu->items[i]);
        }
    }  
}
int dequeu(struct queue *qu)
{
    int el;
    if(qu->rear < qu->front)
    {
        return -1;
    }
    else
    {
        el = qu->items[qu->front];
        qu->front = qu->front +1;
        return el;
    }
}

int peek(struct queue *qu)
{
    int el;
    if(qu->rear < qu->front)
    {
        return -1;
    }
    else
    {
        el = qu->items[qu->rear]; //manditary change
        return el;
    }
}

int empty(struct queue *qu)
{
    if(qu->rear < qu->front)
    {
        return -1;
    }
    else
    {
        return 0;
    }

}

