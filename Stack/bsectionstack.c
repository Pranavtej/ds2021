#include<stdio.h>
#define MAX 10
struct stack
{
    int item[MAX];
    int top;
};
void push(struct stack*,int);
void display(struct stack*);
int pop(struct stack*);
int peek(struct stack*);
int empty(struct stack*);
void main()
{
    int ch,element;
    struct stack s;
    s.top = -1;
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
                printf("Element remove is %d",element);
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
                printf("Top element is %d",element);
            }
            break;
        case 5:
            element = empty(&s);
            if(element == -1)
            {
                printf("Stack is empty");
            }
            else
            {
                printf("Stack contains elements");
            }
            break;
        case 6:
            exit(0);
            break;       
        default:
            printf("Invalid choice");
            break;
        }
    }  
}
void push(struct stack *st,int e)
{
    if(st->top == MAX-1)
    {
        printf("Stack is full");
    }
    else
    {
        st->top = st->top+1;
        st->item[st->top] = e;
    }
}
void display(struct stack *st)
{
    int i;
    for(i=st->top;i>=0;i--)
    {
        printf("\n%d index value is |%d|",i,st->item[i]);
    }
}
int pop(struct stack *st)
{
    int e;
    if(st->top == -1)
    {
        return -1;
    }
    else
    {
        e = st->item[st->top];
        st->top = st->top -1;
        return e;
    }
}

int peek(struct stack *st)
{
    int e;
    if(st->top == -1)
    {
        return -1;
    }
    else
    {
        e = st->item[st->top];
        return e;
    }
}

int empty(struct stack *st)
{
    if(st->top == -1)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}