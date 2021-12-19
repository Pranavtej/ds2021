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
nodeptr deleteAtBeg(nodeptr);
nodeptr deleteAtEnd(nodeptr);
nodeptr deleteBefore(nodeptr);
nodeptr deletionAfter(nodeptr);



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
	p->next=NULL;
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
	if(firstnode->info==k)  //Insertion before first node
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
			case 1:	return(insertAtBeg(firstnode,newnode));
					break;
			case 2:	return(insertAtEnd(firstnode,newnode));
					break;
			case 3: return(insertBeforElement(firstnode,newnode));
					break;
			case 4: return(insertAfterElement(firstnode,newnode));
					break;
		}
	}
}
nodeptr deleteAtBeg(nodeptr firstnode)
{
	nodeptr temp;
	temp = firstnode->next;
	firstnode->next = NULL;
	return temp;
}

nodeptr deleteAtEnd(nodeptr firstnode)
{
	// with single temp varible
	// nodeptr temp;
	// temp = firstnode;
	// while(temp->next->next!=NULL)
	// {
	// 	temp=temp->next;
	// }				
	// temp->next=NULL;
	//with two temp varibles
	nodeptr temp1,temp2;
	temp1 = firstnode;
	while(temp1->next!=NULL)
	{
		temp2=temp1;
		temp1=temp1->next;
	}				
	temp2->next=NULL;
	return firstnode;
}
nodeptr deleteBefore(nodeptr firstnode)
{
	nodeptr temp1,temp2;
	temp1= firstnode;
	int k;
	printf("\nenter the element delete before:");
	scanf("%d",&k);
	if(temp1->info==k)
		printf("\nDeletion is not possible");
	else if(temp1->next->info==k)
	{
		temp2=temp1->next;
		temp1->next=NULL;
		firstnode=temp2;
	}
	else
	{
		while(temp1->next->info!=k)
		{
			temp2=temp1;
			temp1=temp1->next;
		}
		temp2->next=temp1->next;
		temp1->next=NULL;
	}
	return firstnode;
}
nodeptr deletionAfter(nodeptr firstnode)
{
	nodeptr temp1,temp2;
	int k;
	temp1=firstnode;
	printf("\nEnter the element delete after:");
	scanf("%d",&k);
	while(temp1->info!=k)
	{
		temp1=temp1->next;
	}
	if(temp1->next==NULL)
		printf("\ndeletion is not possible");
	else
	{
		temp2=temp1->next;
		temp1->next=temp2->next;
		temp2->next=NULL;
	}
	return firstnode;
}
nodeptr del( nodeptr p)
{
	int c,i,k;
	nodeptr firstnode;
	firstnode=p;
	if(firstnode==NULL)
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
			case 1:	return(deleteAtBeg(firstnode));
					break;
			case 2:	return(deleteAtEnd(firstnode));
					break;
			case 3:	return(deleteBefore(firstnode));
					break;
		 	case 4: return(deletionAfter(firstnode)); 
			 		break;
		}
	}
}
void search(nodeptr p)
{
	int a,i;
	nodeptr temp;
	temp=p;
	printf("\nenter the searching element:");
	scanf("%d",&a);
	i=1;
	while(temp!=NULL)
	{
		if(temp->info==a)
		{
			printf("\nsearching elment is found at location:%d",i);
			return;
		}
		temp=temp->next;
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
	if(temp==NULL)
	{
		printf("\nThere are no Elements\n");
	}
	else
	{
		printf("\nelements are:\n");
		while(temp!=NULL)
		{
			printf("%d-->",temp->info);
			temp=temp->next;
		}
	}
}
