#include<stdio.h>
#define MAX 10
struct  stack
{
    int items[MAX];
    int top;
};
void push(struct stack*,int);
int pop(struct stack*);

void main()
{
    struct stack s;
    s.top = -1;
    int item;
    int i,n,a[10];
    printf("Enter size of array");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nElements before reverse");
    for(i=0;i<n;i++)
    {
        printf("\t%d",a[i]);
    }
    for(i=0;i<n;i++)
    {
        push(&s,a[i]);
    }
    for(i=0;i<n;i++)
    {
        a[i] = pop(&s);
    }
    printf("\nElements after reverse");
    for(i=0;i<n;i++)
    {
        printf("\t%d",a[i]);
    }
}
void push(struct stack *st,int element)
{
    if(st->top == MAX-1)
    {
        printf("****Stack is full****");
    }
    else
    {
        st->top = st->top +1;
        st->items[st->top] = element;
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