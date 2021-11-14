#include<stdio.h>
#define MAX 10
void push();
int pop();
void display();
int peek();
int empty();
struct stack
{
    int top;
    int items[MAX];
};
void main()
{
    struct stack s;
    s.top = -1;
    int item;
    int ch;
    while(1)
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
            printf("Enter element to insert");
            scanf("%d",&item);
            push(&s,item);
            break;
        case 2:
            item = pop(&s);
            if(item == -1)
            {
                printf("\n****Stack is empty****");
            }
            else
            {
                printf("\n****Deleted element is %d****",item);
            }
            break;
        case 3:
            display(&s);
            break;
        case 4:
            item = peek(&s);
            if(item == -1)
            {
                printf("\n****Stack is empty****");
            }
            else
            {
                printf("****Top element of stack is %d****",item);
            }
            break;
        case 5:
            item = empty(&s);
            if(item == -1)
            {
                printf("\n****Stack is empty****");
            }
            else
            {
                printf("\n****Stack contain Elements****");
            }
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("\n****Invalid choice!!****");
            break;
        }
    }
}

void push(struct stack *st,int element)
{
    if(st->top == MAX-1)
    {
        printf("****Stack is full(over Flow)****");
    }
    else
    {
        st->top = st->top+1;
        st->items[st->top]=element;
    }   
}

int pop(struct stack *st)
{
    int element;
    if(st->top == -1)
    {
        return -1;
    }
    else
    {
        element = st->items[st->top];
        st->top = st->top-1;
        return element;
    }
}
void display(struct stack *st)
{
    int i;
    printf("\n***********");
    for(i=st->top;i>=0;i--)
    {
        printf("\n%d index Element is |%d|",i,st->items[i]);
    }
    printf("\n***********");

}
int peek(struct stack *st)
{
    int element;
    if(st->top == -1)
    {
        return -1;
    }
    else
    {
        element = st->items[st->top];
        return element;
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
        return 1;
    }
}