#include<stdio.h>
#include<stdlib.h>

struct node
{
    int coef,expo;
    struct node* next;
};
typedef struct node *nodeptr;
nodeptr insertpoly(nodeptr,int,int);
void display(nodeptr);
void main()
{
    int a,b,n,i;
    struct node* p1head;
    p1head=NULL;

    // Inputing the first polynomial..

    printf("Enter the no of terms of polynomial 1..");
    scanf("%d",&n);
    printf("\nEnter the polynomial..");
    for(i=0;i<n;i++){
        printf("\nEnter the coefficient and exponent of the term..");
        scanf("%d%d",&a,&b);
        p1head=insertpoly(p1head,a,b);
    }
    display(p1head);
}

struct node* insertpoly(struct node* thead,int c,int e)
{
    nodeptr temp;
    nodeptr newnode=(nodeptr)malloc(sizeof(struct node));
    newnode->coef=c;
    newnode->expo=e;
    newnode->next = NULL;
    if(thead==NULL || e > thead->expo){            // for inserting the first node..
        newnode->next=thead;
        return newnode;
    }
    else
    {
        temp = thead;
        while(temp->next!=NULL && temp->next->expo > e)
        {
            temp=temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    return thead;
}

void display(struct node* thead)
{
    nodeptr temp=thead;
    if(temp==NULL){
        printf("\nEmpty..");
    }
    else{
        while(temp->next!=NULL){
        //while(temp!=NULL){
            // printf(" %dx^%d +",temp->coef,temp->expo);
            // temp=temp->next;
            printf("(%dx^%d)",temp->coef,temp->expo);
            temp=temp->next;
            if(temp!=NULL)
            {
                printf("+");
            }
            else
            {
                printf("\n");
            }
        }
       //printf(" %dx^%d ",temp->coef,temp->expo);
       printf("%d",temp->coef);
    }
}