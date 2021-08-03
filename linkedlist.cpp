/******************************************************************************
  linked list re study for build by myself
  push,pop,move,reverse,insert,delete,print

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node *NewNode(int data)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;

    return newnode;
}

void push(struct node** head , int data)
{
    struct node *temp=NewNode(data);
    temp->next=*head;
    *head=temp;
}

void printNode(struct node *head)
{
    struct node *curr=head;

    while(curr!=NULL)
    {
        printf("%d -> ",curr->data);
        curr=curr->next;
    }
}

void insertNode(struct node *head,int data,int newdata)
{
    struct node *curr=head;
    struct node *newnode=NewNode(newdata);
    struct node *prev;

    while(curr->data!=data)
    {
        prev=curr;
        curr=curr->next;
    }
    newnode->next=curr;
    prev->next=newnode;

}

void insertNode2(struct node *head,int data,int newdata)
{
    struct node *curr=head;
    struct node *newnode=NewNode(newdata);

    while(curr->data!=data)
    {
        curr=curr->next;
    }
    newnode->next=curr->next;
    curr->next=newnode;

}

void delNode(struct node *head,int data)
{
    struct node *curr=head;
    struct node *prev;

    while(curr->data!=data)
    {
        prev=curr;
        curr=curr->next;
    }
    prev->next=curr->next;
    free(curr);

}

void delNode2(struct node *head,int data)
{
    struct node *curr=head;
    struct node *temp=NULL;

    while(curr->next->data!=data)
    {
        curr=curr->next;
    }
    temp=curr->next;
    curr->next=curr->next->next;
    free(temp);

}

void append(struct node *head,int data)
{
    struct node *curr=head;

    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    curr->next=NewNode(data);

}

int pop(struct node **head)
{
    struct node *curr=*head;
    int ret = curr->data;

    (*head)=(*head)->next;
    free(curr);

    return ret;
}

void moveNode(struct node **des, struct node **src)
{
    struct node *temp=*src;

    *src = (*src)->next;
    temp->next=*des;
    *des=temp;
}


void reverseNode(struct node **headref)
{
    struct node *Next=NULL;
    struct node *curr=*headref;
    struct node *prev=NULL;

    while(curr!=NULL)
    {
        Next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=Next;
    }
    *headref=prev;
}

int main()
{
   struct node *head =NULL;

   push(&head,20);
   push(&head,10);
   push(&head,40);

   insertNode2(head,20,30);
   insertNode2(head,20,50);

   delNode2(head,50);
   delNode2(head,10);

   append(head,80);
   append(head,90);
   pop(&head);

   struct node * newnode=NewNode(99);
   moveNode(&newnode,&head);
  // moveNode(&new,&head);

   printNode(head); printf("***");  printNode(newnode); printf("\n");

   reverseNode(&head);  printNode(head); printf("***");  reverseNode(&newnode); printNode(newnode);




    return 0;
}
