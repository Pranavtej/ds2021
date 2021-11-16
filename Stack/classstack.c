#include<stdio.h>
#define MAX 3
//void push(struct stack*,int);
//void display(struct stack*);
//int pop(struct stack*);
//int peek (struct stack*);
//int empty(struct stack*);
struct stack
{
    int items[MAX];
    int top;
};
void main()
{
    struct stack s;
    s.top =-1;
    int ch,element;
    while (1)
    {
        printf("\n1.push");
        printf("\n2.pop");
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
            push(&s,element);
            break;
        case 2:
            element = pop(&s);
            if(element == -1)
            {
                printf("Stack is empty");    
            }
            else
            {
                printf("%d is removed",element);
            }
            break;
        case 3:
            display(&s);
            break;
        case 4:
            element = peek(&s);
            if(element == -1)
            {
                printf("Stack is empty");    
            }
            else
            {
                printf("%d is top element",element);
            }

            break;
        case 5:
            element = empty(&s);
            if(element == 0)
            {
                printf("Stack is empty");    
            }
            else
            {
                printf("Stack contatin elements");
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
void push(struct stack *st,int element)
{
    if(st->top == MAX-1)
    {
        printf("Stack is full (over flow)");
    }
    else
    {
        st->top = st->top+1;
        st->items[st->top]=element;
    }
}

void display(struct stack *st)
{
    int i;
    for(i=st->top;i>=0;i--)
    {
        printf("\n%d index value is |%d|",i,st->items[i]);
    }
}
int pop(struct stack *st)
{
    int item;
    if(st->top == -1)
    {
        return -1;
    }
    else{
        item = st->items[st->top];
        st->top = st->top-1;
        return item;

    }    
}
int peek(struct stack *st)
{
    int item;
    if(st->top == -1)
    {
        return -1;
    }
    else
    {
        item = st->items[st->top];
        return item;
    }
}
int empty(struct stack *st)
{
    if(st->top == -1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}