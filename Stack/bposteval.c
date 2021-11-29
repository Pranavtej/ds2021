#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define MAX 10

struct stack
{
    int items[MAX];
    int top;
};
double eval(char []);\
int isdigit(char);
double operation(char,double,double);
void push(struct stack *,double);
double pop(struct stack *);
int empty(struct stack *);
void main()
{
    char exp[10];
    printf("Enter expersion");
    scanf("%s",exp);
    printf("Enter expersion is %s",exp);
    printf("Result is %f",eval(exp));
    
}
double eval(char exp[])
{
    double op1,op2,val;
    int i;
    char c;
    struct stack s;
    s.top = -1;
    for(i=0;(c=exp[i])!='\0';i++)
    {
        if(isdigit(c))
        {
            push(&s,(double)c-'0');
        }
        else
        {
            op2=pop(&s);
            op1=pop(&s);
            val = operation(c,op1,op2);
            push(&s,val);
        }
    }
    return pop(&s);
}
int isdigit(char symb)
{
	return(symb>='0'&&symb<='9');
}
void push(struct stack *st,double a)
{
	if(st->top==MAX-1)
	{
		printf("\nstack is overflow");

	}
	else
	{
		st->top++;
		st->items[st->top]=a;
	}
}
double pop(struct stack *st)
{
	double a;
	if(empty(st))
		return -1;
	else
	{
		a=st->items[st->top];
		st->top--;
		return a;
	}
}
int empty(struct  stack *st)
{
	if(st->top==-1)
		return 1;
	else
		return 0;
}

double operation(char c,double op1,double op2)
{
   switch(c)
	{
		case '+': return(op1+op2);
                  break;
		case '-': return(op1-op2);
                break;
		case '*': return(op1*op2);
                break;
		case '/': return(op1/op2);
                break;
		case '$': return(pow(op1,op2));
                break;
		default: printf("\nillegal operation %c",c);
			exit(0);
            break;
	}

}