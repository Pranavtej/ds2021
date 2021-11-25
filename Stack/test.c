#include<stdio.h>
int isdigit(char);

void main()
{
    char c='5';
    printf("\ncharacter :: %c",c);
    printf("\n asci in floot :: %f ",(double)c);
    printf("\n asci in number :: %d",(int)c);
    printf("\n numarical :: %d",(int)c-0);
    printf("give value is :: %d",isdigit('9'));


}

int isdigit(char symb)
{
	return(symb>='0'&&symb<='9');
}