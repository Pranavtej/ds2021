/* CIRCULAR Linked List operations */
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *next;
};
typedef struct node *nodeptr;
nodeptr getnode();
nodeptr insert();
nodeptr del();
void traversal();
main()
{
	nodeptr first,last;
	int choice;
	clrscr();
	first=NULL;
	while(1)
	{
		printf("\n*************************\n\n\tMENU\n**********************\n");
		printf("\n1.adding a node\n2.delete a node");
		printf("\n3.traversal\n");
		printf("4.exit\n*******************\nEnter your choice:");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:	first=insert(first);
				traversal(first);
				break;
			case 2:	first=del(first);
				traversal(first);
				break;
			case 3: traversal(first);
				break;
			case 4:	exit(0);
		}
	}
}
nodeptr getnode()
{
	nodeptr p;
	p=(nodeptr)malloc(sizeof(struct node));
	p->info=0;
	p->next=p;
	return p;
}
nodeptr insert(nodeptr p)
{
	nodeptr p1,p2;
	int k,ch,i;
	p1=p;
	p2=getnode();
	printf("\nenter inserted element:");
	scanf("%d",&p2->info);
	if(p==NULL)
	{
		p2->next=p2;
		p=p2;
		return p;
	}
	else
	{
		printf("\ninsert\n1.at beg\n2.at end\n3.insert before\n4.insert after\nenter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	while(p1->next!=p)
					p1=p1->next;
				p2->next=p;
				p1->next=p2;
				p=p2;
				return(p);
			case 2:	while(p1->next!=p)
					p1=p1->next;
				p2->next=p;
				p1->next=p2;
				return p;
			case 3: printf("\nEnter the element insert before:");
				scanf("%d",&k);
				if(p1->info==k)
				{
					while(p1->next!=p)
						p1=p1->next;
					p2->next=p;
					p1->next=p2;
					p=p2;
				}
				else
				{
					while(p1->next->info!=k)
						p1=p1->next;
					p2->next=p1->next;
					p1->next=p2;
					
				}
				return p;
			case 4: printf("\nEnter the element insetr after:");
				scanf("%d",&k);
				while(p1->info!=k)
					p1=p1->next;
				p2->next=p1->next;
				p1->next=p2;
				return p;
		}
	}
}
nodeptr del( nodeptr p)
{

	int c,i,k;
	nodeptr p1,p2;
	p1=p;
	if(p1==NULL)
	{
		printf("\nlist is empty");
		return p;
	}
	else
	{
		printf("\nDelete\n1.at begining\n2.at end\n3.delete before\n4.delete after");
		printf("\nEnter your choice:");
		scanf("%d",&c);
		switch(c)
		{
			case 1:	if(p1->next==p1)
				{
					p=NULL;
					return p;
				}
				else
				{
					while(p1->next!=p)
						p1=p1->next;
					p2=p->next;
					p1->next=p2;
					p->next=NULL;
					return p2;
				}
			case 2:	if(p1->next==p1)
				{
					p=NULL;
					return p;
				}
				while(p1->next->next!=p)
					p1=p1->next;
				p1->next=p;
				return p;
			case 3:	printf("\nenter the element delete before:");
				scanf("%d",&k);
				if(p1->info==k)
					printf("\nDeletion is not possible");
				else if(p1->next->info==k)
				{
					while(p1->next!=p)
						p1=p1->next;
					p1->next=p->next;
					p2=p->next;
					p->next=NULL;
					p=p2;
				}
				else
				{
					while(p1->next->info!=k)
					{
						p2=p1;
						p1=p1->next;
					}
					p2->next=p1->next;
					p1->next=NULL;
				}
				return p;
			case 4: printf("\nEnter the element delete after:");
				scanf("%d",&k);
				while(p1->info!=k)
					p1=p1->next;
				if(p1->next==p)
					printf("\ndeletion is not possible");
				else
				{
					p2=p1->next;
					p1->next=p2->next;
					p2->next=NULL;
				}
				return p;
		  }
	}
}

void traversal(nodeptr p)
{
	nodeptr p1;
	p1=p;
	printf("\nelements are:\n");
	while(p1->next!=p)
	{
		printf("%d-->",p1->info);
		p1=p1->next;
	}
	printf("%d",p1->info);
}
