#include<stdio.h>
int isdigit(char);

void main()
{
    char c = 'a'; //97 in ASCII
    double x = (double)c -'0'; 
    printf("%f\n", x);
    printf("%f\n",(double)'0');
 
    printf("%f",(double)'9');
}

int isdigit(char symb)
{
	return(symb>='0'&&symb<='9');
}