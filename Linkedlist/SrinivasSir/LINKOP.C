/* Linked List operations */
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
void search();
nodeptr reverse();
void traversal();
main()
{
	nodeptr first;
	int choice;
	clrscr();
	first=NULL;
	while(1)
	{
		printf("\n*************************\n\n\tMENU\n**********************\n");
		printf("\n1.adding a node\n2.delete a node\n3.search an element");
		printf("\n4reverse linked list\n5.traversal\n");
		printf("6.exit\n*******************\nEnter your choice:");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:	first=insert(first);
				traversal(first);
				break;
			case 2:	first=del(first);
				traversal(first);
				break;
			case 3: search(first);
				break;
			case 4:	last=reverse(first);
				traversal(last);
				break;
			case 5: traversal(first);
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
		p=p2;
		return p;
	}
	else
	{
		printf("\ninsert\n1.at beg\n2.at end\n3.insert before\n4.insert after\nenter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	p2->next=p1;
				p=p2;
				return(p);
			case 2:	while(p1->next!=NULL)
					p1=p1->next;
				p1->next=p2;
				return p;
			case 3: printf("\nEnter the element insert before:");
				scanf("%d",&k);
				if(p1->info==k)
				{
					p2->next=p1;
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
			case 1:	p2=p1->next;
				p1->next=NULL;
				return p2;
			case 2:	while(p1->next->next!=NULL)
					p1=p1->next;
				p1->next=NULL;
				return p;
			case 3:	printf("\nenter the element delete before:");
				scanf("%d",&k);
				if(p1->info==k)
					printf("\nDeletion is not possible");
				else if(p1->next->info==k)
				{
					p2=p1->next;
					p1->next=NULL;
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
				if(p1->next==NULL)
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
void search(nodeptr p)
{
	int a,i;
	nodeptr p1;
	p1=p;
	printf("\nenter the searching element:");
	scanf("%d",&a);
	i=1;
	while(p1!=NULL)
	{
		if(p1->info==a)
		{
			printf("\nsearching elment is found at location:%d",i);
			return;
		}
		p1=p1->next;
		i++;
	}
	printf("\nsearching element is not found");
}
nodeptr reverse(nodeptr p)
{
	nodeptr p1,p2,p3;
	p1=p;
	p2=getnode();
	p2->info=p1->info;
	while(p1->next!=NULL)
	{
		p1=p1->next;
		p3=getnode();
		p3->info=p1->info;
		p3->next=p2;
		p2=p3;
	}
	return p2;
}
void traversal(nodeptr p)
{
	nodeptr p1;
	p1=p;
	printf("\nelements are:\n");
	while(p1!=NULL)
	{
		printf("%d-->",p1->info);
		p1=p1->next;
	}
}
