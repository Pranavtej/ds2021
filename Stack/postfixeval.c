#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 10
struct stack 
{
    int item[MAX];
    int top;
};

double oper(char,double,double);
void push(struct stack *,double);
double pop(struct stack *);
int empty(struct stack *);
double eval(char[]);
int isdigit(char);

void main()
{
    char exp[MAX];
    printf("Enter postfix expression");
    scanf("%s",exp);
    printf("\nOriginal postfix expression :%s",exp);
    printf("\nOriginal postfix expression :%f",eval(exp));

}
double eval(char exp[])
{
    int i;
    char c;
    double op1,op2,val;
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
            printf("\n%c",c);
            op2 = pop(&s);
            op1 = pop(&s);
            val = oper(c,op1,op2);
            push(&s,val);
        }
    }
        return (pop(&s));       
    
}

int isdigit(char sym)
{
    return(sym>='0'&& sym<='9');
}


double oper(char sym, double op1,double op2)
{
    switch(sym)
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
		default: printf("\nillegal operation %c",sym);
			exit(0);
            break;
	}

}


void push(struct stack *st, double a)
{
	if(st->top==MAX-1)
	{
		printf("\nstack is overflow");

	}
	else
	{
		st->top++;
		st->item[st->top]=a;
	}
}
double pop(struct stack *st)
{
	double a;
	if(empty(st))
		return -1;
	else
	{
		a=st->item[st->top];
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



