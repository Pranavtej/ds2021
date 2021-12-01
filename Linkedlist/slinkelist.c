/*
 ============================================================================
 Name        : slinkelist.c
 Author      : Raghu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include<stdio.h>
#include <stdlib.h>
struct NODE {
    int data;
    struct NODE*next;
};
struct NODE *first , *last, *temp, *temp1;
void create();
void insert();
void insertbeg();
void insertend();
void insertmid();
void delete();
void deletebeg();
void deleteend();
void deletemid();
void display();
int main(void) {
    char ch;
    //clrscr();
    first=last=NULL;
    while(1) {
        printf("\n\n****************-->MENU<--**************** \n");
        printf("\n1.creation");
        printf("\n2.inseration");
        printf("\n3.deletion");
        printf("\n4.display");
        printf("\n5.exit");
        printf("\n\t\tenter ur choice:");
        fflush(stdin);
        scanf("%c", &ch);
        switch(ch) {
            case '1': create(); break;
            case '2': insert(); break;
            case '3': delete(); break;
            case '4': display();break;
            default : exit(0);
        }
    }
    return EXIT_SUCCESS;

}
void create() {
    char ch;
    struct NODE *newnode=(struct NODE*)malloc(sizeof(struct NODE));
    while(1) {
        printf("\nenter an element:");
        scanf("%d", &newnode->data);
        newnode->next=NULL;
        if(first==NULL)
            first=last=newnode;
        else {
            last->next=newnode;
            last=newnode;
        }
        printf("\n\tdo  u want to continue....(Y/N):");
        fflush(stdin);
        scanf("%c", &ch);
        if (ch=='Y'||ch=='Y')
            newnode=(struct NODE*)malloc(sizeof(struct NODE));
        else
            break;
    }
}
void insert() {
    char ch;
    printf("\n\t\t1.insertion  AT  begin");
    printf("\n\t\t2.insertion  AT  end");
    printf("\n\t\t3.insertion  AT  middle");
    printf("\n\tenter ur choice:");
    fflush(stdin);
    scanf("%c", &ch);
    switch(ch) {
        case '1':insertbeg(); break;
        case '2':insertend(); break;
        case '3':insertmid(); break;
        default :printf("\n\t\twrong entry");
    }
}
void insertbeg() {
    struct NODE *newnode=(struct NODE*)malloc(sizeof(struct NODE));
    printf("\nenter AN element that IS TO BE INSerted At first:");
    scanf("%d", &newnode->data);
    newnode->next=NULL;
    if(first!=NULL) {
        newnode->next=first;
        first=newnode;
        printf("\n\t%d IS INserted At First successfully", newnode->data);
    }
    else
        printf("\n THE List IS Not Yet Created");
}
void insertend() {
    struct NODE*newnode=(struct NODE*)malloc(sizeof (struct NODE));

    printf("\n enter An element THAT IS TO be inserted At Last:");
    scanf("%d", &newnode->data);
    newnode->next=NULL;
    if(first!=NULL) {
        temp=first;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newnode;
        printf("\n\t%d IS INSERTED At Last successfully", newnode->data);
    }
    else
        printf("\n The List IS Not Yet Created");
}
void insertmid() {
    struct NODE *newnode=(struct NODE*)malloc(sizeof(struct NODE));
    int loc, i;
    printf("\n Enter Location That The Element IS  To Be Inserted:");
    scanf("%d", &loc);
    if(loc==1)
        insertbeg();
    else {
        printf("\nEnter An Element:");
        scanf("%d", &newnode->data);
        newnode->next=NULL;
        for(i=1, temp=first;i<=loc-2;i++, temp=temp->next);
        if(temp==NULL)
            printf("\n Invalid location");
        else {
            newnode->next=temp->next;
            temp->next=newnode;
            printf("\n\t%d IS Inserted At %d position successfully", newnode->data, loc);
        }
    }
}
void delete() {
    char ch;
    printf("\n\t\t1.deletion At Begin");
    printf("\n\t\t2.deletion At End");
    printf("\n\t\t3.deletion At Middle");
    printf("\n\tEnter Ur Choice:");
    fflush(stdin);
    scanf("%c", &ch);
    switch(ch) {
        case '1':deletebeg(); break;
        case '2':deleteend(); break;
        case '3':deletemid(); break;
        default :printf("\n\t\twrong Entry");
    }
}
void deletebeg() {
    temp=first;
    if(first==NULL)
        printf("\n the list is empty");
    else {
        if(first->next==NULL)
            first=NULL;
        else
            first=first->next;
        printf("\n\t %d IS deleted successfully", temp->data);
    }
    free(temp);
}
void deleteend() {
    if(first==NULL)
        printf("\n The List IS Empty");
    else if(first->next==NULL) {
        printf("\n\t %d IS Deleted successfully", first->data);
        free(first);
        first=last=NULL;
    }
    else {
        for(temp=first;temp->next!=NULL;temp=temp->next);
        temp1=temp;

        temp1->next=NULL;
        printf("\n\t%d IS Deleted successfully", last->data);
        free(temp);

    }
}
void deletemid() {
    int loc, i;
    struct NODE *p;
    printf("\nEnter Location of The Element That is To be Deleted:");
    scanf("%d", &loc);
    if(loc==1)
        deletebeg();
    else {
        for(i=1, temp=first;i<=loc-2;i++, temp=temp->next);

        if(temp->next==NULL)
            printf("\nInvalid location");
        else {
            p=temp->next;
            temp->next=temp->next->next;
            printf("\n\t%d IS Deleted successfully", p->data);
            free(p);
        }
    }
}
void display() {
    if(first!=NULL) {
        printf("\n The Elements in the linked list are\n\n");
        for(temp=first;temp!=NULL;temp=temp->next)
            printf("%d->", temp->data);
        printf("NULL");
    }
    else
        printf("\n\tThe List is Empty");
}
