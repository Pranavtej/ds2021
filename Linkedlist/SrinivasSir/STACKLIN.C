/* STACK OPERATIONS USING LINKED LISTS */
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *next;
};
typedef struct node *nodeptr;
struct stack
{
	nodeptr top;
};
nodeptr getnode();
void push(struct stack *,int);
int pop(struct stack *);
void display(struct stack *);
int peek(struct stack *);
main()
{
	int choice,x;
	struct stack s;
	clrscr();
	s.top=NULL;
	while(1)
	{
		printf("\n*************************\n\n\tMENU\n**********************\n");
		printf("1.push\n2.pop\n3.empty\n4.peek\n5.display\n");
		printf("6.exit\n*******************\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1: printf("\nenter the element:");
			scanf("%d",&x);
			push(&s,x);
			display(&s);
			break;
		case 2:	x=pop(&s);
			if(x==-1)
				printf("\nstack is empty");
			else
				printf("deleted item is:%d",x);
			display(&s);
			break;
		case 3:	x=empty(&s);
			if(x==1)
				printf("\nstack is empty");
			else
				printf("\nstack is nonempty");
			break;
		case 4:	x=peek(&s);
			if(x==-1)
				printf("\nStack is empty");
			else
				printf("\ntop element of the stack:%d",x);
			break;
		case 5:	display(&s);
			break;
		case 6:	exit(0);
		}
	}
}
nodeptr getnode()
{
	nodeptr p;
	p=(nodeptr)malloc(sizeof(struct node));
	p->info=0;
	p->next=NULL;
	return p;
}
void push(struct stack *st,int a)
{
	nodeptr p;
	p=getnode();
	p->info=a;
	if(st->top==NULL)
	{
	  st->top=p;
	}
	else
	{
		p->next=st->top;
		st->top=p;
	}
 }
int pop(struct stack *st)
{
       int t;
       if(empty(st))
		return -1;
	else
	{
	     t=st->top->info;
	     st->top=st->top->next;
	     return t;
	}
}
void display(struct stack *st)
{
	nodeptr p1;
	p1=st->top;
	printf("\nelements are:\n");
	printf("(top)");
	while(p1!=NULL)
	{
		printf("%d<--",p1->info);
		p1=p1->next;
	}
}
int empty(struct stack *st)
{
	if(st->top==NULL)
		return 1;
	else
		return 0;
}
int peek(struct stack *st)
{
	if(st->top==NULL)
		return -1;
	else
		return st->top->info;
}