/* priority queue using linked list */
#include<stdio.h>
struct node
{
	int info,priority;
	struct node *next;
};
typedef struct node *nodeptr;
struct pqueue
{
	nodeptr front;
};
nodeptr getnode();
void insert();
int del();
void display();
main()
{
	int ch,x,p;
	struct pqueue pq;
	pq.front=NULL;
	while(1)
	{
		printf("\n*******\nMENU\n********\n");
		printf("\n1.insert\n2.delete\n3.display\n4.exit\n");
		printf("\nenter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	printf("\nenter the number to insert:");
				scanf("%d",&x);
				printf("\nenter the priority of number:");
				scanf("%d",&p);
				insert(&pq,x,p);
				printf("\nelements are :");
				display(&pq);
				break;
			case 2:	x=del(&pq);
				if(x==-1)
					printf("\npriority queue is empty");
				else
					printf("\ndeleted element is:%d",x);
				printf("\nelements are :");
				display(&pq);
				break;
			case 3:	printf("\nelements are :");
				display(&pq);
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
	p->priority=0;
	p->next=NULL;
	return p;
}
void insert(struct pqueue *pq,int a,int b)
{
	nodeptr p,p1,p2;
	p=getnode();
	p->info=a;
	p->priority=b;
	if(pq->front==NULL)
		pq->front=p;
	else
	{
		p1=pq->front;
		if(p1->priority>p->priority)
		{
			p->next=p1;
			pq->front=p;
		}
		else
		{
			while((p1->priority<=p->priority)&&(p1!=NULL))
			{
				p2=p1;
				p1=p1->next;
			}
			p2->next=p;
			p->next=p1;
		}
	}
}
int del(struct pqueue *pq)
{
	int x;
	if(empty(pq))
		return -1;
	else
	{
		x=pq->front->info;
		pq->front=pq->front->next;
		return x;
	}
}
int empty(struct pqueue *pq)
{
	if(pq->front==NULL)
		return 1;
	else
		return 0;
}
void display(struct pqueue *pq)
{
	nodeptr p;
	p=pq->front;
	while(p!=NULL)
	{
		printf("%d-->",p->info);
		p=p->next;
	}

}

