#include <iostream>
using namespace std;

class Node{
public:
  int data;
  Node *next;
};

void push(Node **headref,int data)
{
  Node *new_node = new Node();
  new_node->data=data;
  new_node->next=*headref;
  *headref=new_node;
}

void insertAfter(Node *head,int data)
{
  Node *curr=head;

  if(curr==NULL) return;

  Node *new_node=new Node();

  new_node->data=data;
  new_node->next=curr->next;
  curr->next=new_node;

}
void deleteNode(Node **headref,int key)
{
  Node *curr=*headref;
  Node *prev=NULL;

  if(curr!=NULL && curr->data==key)
  {
    *headref=curr->next;
    delete curr;
    return;
  }

  while(curr!=NULL && curr->data!=key)
  {
    prev=curr;
    curr=curr->next;
  }
  Node *temp=curr;
  prev->next=curr->next;
  delete curr;

}


void append( Node **headref,int data)
{
  Node *curr=*headref;
  Node *new_node=new Node();

  new_node->data=data;

  if(curr==NULL)
  {
    *headref=new_node;
    return;
  }

  while(curr->next!=NULL)
  {
    curr=curr->next;
  }

  curr->next=new_node;
  new_node->next=NULL;

}

void printList(Node *head)
{
  while(head!=NULL)
  {
    printf("%d ->",head->data);
    head=head->next;
  }
}

int getCount(Node *head)
{
  Node *curr=head;
  int count=0;

  while(curr!=NULL)
  {
    count ++;
    curr=curr->next;
  }
  return count;
}

bool search(Node *head,int x)
{
  Node *curr=head;
  while(curr!=NULL)
  {
    if(curr->data==x)
    return true;

    curr=curr->next;
  }
}

void reverseList(Node **headref)
{
  Node *Next=NULL;
  Node *curr=*headref;
  Node *prev=NULL;

 while(curr!=NULL)
 {
   Next=curr->next;
   curr->next=prev;
   prev=curr;
   curr=Next;
 }
 *headref=prev;
}

void moveNode(Node **dst,Node **src)
{
  Node *curr=*src;

  (*src)=(*src)->next;
  curr->next=*dst;
  *dst=curr;
}

int main()
{
  Node *head=NULL;

#if 0
    append(&head,6);
    push(&head,7);
    push(&head,1);
    push(&head,4);
    insertAfter(head->next,8);
    deleteNode(&head,4);
    printList(head);
#else
    Node *dst=NULL;

    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
    push(&head, 4);
    push(&head, 8);

    cout << "Created Linked List: ";
    printList(head);
    deleteNode(&head, 4);
    cout << "\nLinked List after Deletion at position 4: ";
    printList(head);

    cout<<"count of nodes :"<<getCount(head)<<endl;

    search(head,8)? cout<<"YES" : cout<<"NO" <<endl;
    cout<<endl;
    reverseList(&head);
    cout<<"Reverse List: "<<endl;
    printList(head);

    cout<<endl;
    while(head!=NULL)
    {
       moveNode(&dst,&head);
    }

    cout<<"move node: "<<endl;
    printList(dst);
#endif

  return 0;
}
