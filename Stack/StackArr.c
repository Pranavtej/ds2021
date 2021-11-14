#include<stdio.h>
#define MAX 4
int top=-1;
int stack[MAX];
void push(int);
void display();
int pop();
int peek();
void main()
{
    int ch;
    int element;
    do
    {
        printf("\n1.push");
        printf("\n2.pop");
        printf("\n3.Display");
        printf("\n4.peek");
        printf("\n5.Exit");
        printf("\n\nEnter your Choice :");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:
              printf("Enter element to insert");
              scanf("%d",&element);
              push(element);
              break;
            case 2:
              element=pop();
              if(element == -1)
              {
                printf("Stack is empty");

              }
              else
              {
                printf("%d element removed",element);
              }
              break;
            case 3:
              display();
              break;
            case 4:
              element=peek();
              if(element == -1)
              {
                printf("Stack is empty");

              }
              else
              {
                printf("%d is first element",element);
              }
              break;
            case 5:
              exit(0);
              break;
        default:
              printf("\nInvalid choice!!");
              break;
        }
    } while (1);
}
void push(int element)
{
  if(top == MAX-1)
  {
    printf("Over flow");
  }
  else
  {
    top=top+1;
    stack[top]=element;
  }
}
void display()
{
  int i;
  if(top == -1)
  {
    printf("Stack is empty");
  }
  else
  {
    for(i=top;i>=0;i--)
    {
      printf("%d index Element is %d\n",i,stack[i]);
    }
  }
}
int pop()
{
  int element;
  if(top == -1)
  {
    return -1;
  }
  else
  {
    element = stack[top];
    top = top-1;
    return element;
  }
}

int peek()
{
  int element;
  if(top == -1)
  {
    return -1;
  }
  else
  {
    element = stack[top];
    return element;
  }
}