#include<stdio.h>
#define MAX 10
//void push(struct stack*);
//int pop(struct stack*);;
struct stack
{
    int items[MAX];
    int top;
};
void main()
{
    int i,n,a[10];
    struct stack s;
    s.top = -1;
    printf("Enter size of list");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Elements before reversing");
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }

    for(i=0;i<n;i++)
    {
       push(&s,a[i]);
    }

    for(i=0;i<n;i++)
    {
      a[i] = pop(&s);
    }

    printf("Elements after reversing");
    for(i=0;i<n;i++)
    {
        printf("\n%d index values are %d",i,a[i]);
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


