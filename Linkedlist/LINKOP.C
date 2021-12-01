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
nodeptr insert(nodeptr);
nodeptr del(nodeptr);
void search(nodeptr);
nodeptr reverse(nodeptr);
void traversal(nodeptr);
nodeptr insertAtBeg(nodeptr,nodeptr);
nodeptr insertAtEnd(nodeptr,nodeptr);
nodeptr insertBeforElement(nodeptr,nodeptr);
nodeptr insertAfterElement(nodeptr,nodeptr);


main()
{
	nodeptr first,last;
	int choice;
	//clrscr();
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
	p->next=0;
	return p;
}
nodeptr insertAtBeg(nodeptr firstnode,nodeptr newnode)
{
	newnode->next=firstnode;
	firstnode = newnode;
	return firstnode;
}
nodeptr insertAtEnd(nodeptr firstnode,nodeptr newnode)
{
	nodeptr temp;
	temp=firstnode;
	while (temp->next!=NULL)
	{
		temp = temp->next;
	}
	temp->next = newnode;
	return firstnode;
}
nodeptr insertBeforElement(nodeptr firstnode,nodeptr newnode)
{
	int k;
	nodeptr temp;
	temp = firstnode;
	printf("\nEnter the element insert before:");
	scanf("%d",&k);
	if(firstnode->info==k)
	{
		newnode->next=firstnode;
		firstnode = newnode;
	}
	else
	{
		while(temp->next->info!=k)
		{
			temp=temp->next;
		}
		newnode->next=temp->next;
		temp->next=newnode;
	}
	return firstnode;
}
nodeptr insertAfterElement(nodeptr firstnode,nodeptr newnode)
{
	int k;
	nodeptr temp;
	temp=firstnode;
	printf("\nEnter the element insetr after:");
	scanf("%d",&k);
	while(temp->info!=k)
	{
		temp=temp->next;
	}
	newnode->next=temp->next;
	temp->next=newnode;
	return firstnode;
}

nodeptr insert(nodeptr p)
{
	nodeptr firstnode,newnode;
	int ch;
	firstnode=p;
	newnode=getnode();
	printf("\nenter inserted element:");
	scanf("%d",&newnode->info);
	if(p==NULL)
	{
		firstnode=newnode;
		return firstnode;
	}
	else
	{
		printf("\ninsert\n1.at beg\n2.at end\n3.insert before\n4.insert after\nenter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	
				return(insertAtBeg(firstnode,newnode));
			case 2:	
				return(insertAtEnd(firstnode,newnode));
			case 3: 
				return(insertBeforElement(firstnode,newnode));
			case 4: 
				return(insertAfterElement(firstnode,newnode));
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
	nodeptr temp;
	temp=p;
	printf("\nelements are:\n");
	while(temp!=NULL)
	{
		printf("%d-->",temp->info);
		temp=temp->next;
	}
}
