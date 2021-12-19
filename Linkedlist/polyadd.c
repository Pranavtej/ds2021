#include<stdio.h>
#include<stdlib.h>
struct node
{
    int exp,coef;
    struct node *next;
};
typedef struct node *nodeptr;
nodeptr create(); 
nodeptr getnode();
void display(nodeptr);
main()
{
    nodeptr first,second,res;
    first = create();
    printf("\nFirst polynomial is:");
	display(first);

}
nodeptr getnode()
{
	nodeptr p;
	p=(nodeptr)malloc(sizeof(struct node));
	p->exp=p->coef=0;
	p->next=NULL;
	return p;
}
nodeptr create()
{
    nodeptr p,p1,p2;
    p1 = getnode();
    p2 = getnode();
    p = p1;
    printf("\nenter the expantions in order\n");
	printf("\nEnter the exp -1 at END\n");
	printf("enter the coef &  exp :");
	scanf("%d%d",&p2->coef,&p2->exp);
    while(p2->exp!=-1)
    {
        p1->next = p2;
        p1=p2;
        p2 = getnode();
        printf("\nenter the coef & exp :");
		scanf("%d%d",&p2->coef,&p2->exp);
    }
    p=p->next;
	return p;
}
void display(nodeptr p)
{
	nodeptr p1;
	p1=p;
	while(p1!=NULL)
	{
		printf("%d*X^%d+",p1->coef,p1->exp);
		p1=p1->next;
	}
}
