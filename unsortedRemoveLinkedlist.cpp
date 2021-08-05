
#include <unordered_set>
#include <iostream>
using namespace std;

class Node{
public:
  int data;
  Node *next;
};

void push(Node *&headref,int data)
{
  Node *new_node = new Node();
  new_node->data=data;
  new_node->next=headref;
  headref=new_node;
}


void printList(Node *head)
{
  while(head!=NULL)
  {
    printf("%d ->",head->data);
    head=head->next;
  }
}


Node *reverseList(Node *&headref)
{
  Node *Next=NULL;
  Node *curr=headref;
  Node *prev=NULL;

 while(curr!=NULL)
 {
   Next=curr->next;
   curr->next=prev;
   prev=curr;
   curr=Next;
 }
 headref=prev;

 return headref;
}

void moveNode(Node **dst,Node **src)
{
  Node *curr=*src;

  (*src)=(*src)->next;
  curr->next=*dst;
  *dst=curr;
}

void removeDuplicate(Node *head)
{
  Node *curr=head;
  Node *Next=nullptr;

  while(curr->next!=nullptr)
  {
    if(curr->data == curr->next->data)
    {
      Next=curr->next->next;
      delete curr->next;
      curr->next=Next;
    }
    else{
      curr=curr->next;
    }
  }
}

void unsortremoveDuplicate(Node *head)
{
  unordered_set<int> seen;
  Node *curr=head;
  Node *prev=NULL;

  while(curr !=nullptr)
  {
    //If current value is seen before
    if(seen.find(curr->data) != seen.end())    // curr->data is in the loop
    {
      prev->next=curr->next;
      delete curr;
      curr=prev->next;
    }
    else
    {
      seen.insert(curr->data);
      prev=curr;
      curr=curr->next;
    }

  }
}

int main()
{
    Node *head=NULL;
    int i;

    push(head, 10);
    push(head, 12);
    push(head, 11);
    push(head, 11);
    push(head, 12);
    push(head, 11);
    push(head, 10);
    push(head, 13);
    push(head, 14);
    push(head, 15);
    push(head, 13);

    cout << "Created Linked List: ";
    printList(head);
      cout << "\nRemoved duplicate Linked List: ";
  //  removeDuplicate(head);
  unsortremoveDuplicate(head);
    printList(head);

  return 0;
}
