
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



void pairwiseSwap(Node *&head)
{
   Node *curr=head;
   Node *prev=nullptr;
   Node *Next=nullptr;

   while(curr!=nullptr && curr->next!=nullptr)
   {
     Next=curr->next;
     curr->next=Next->next;
     Next->next=curr;

     if(prev==nullptr) head=Next;
     else  prev->next=Next;

     prev=curr;
     curr=curr->next;

   }
}

void pairwiseSwap2(Node *&headref)
{
  Node *curr=(headref)->next;
  Node *prev=headref;
  Node *Next=NULL;

  headref= curr;

  while(curr!=NULL)
  {
     Next=curr->next;
     curr->next=prev;
     if(Next==nullptr || Next->next==nullptr)
     {
        prev->next=Next;
        break;
     }
     prev->next=Next->next;

     prev=Next;
     curr=prev->next;
  }
}
int main()
{
    Node *head=NULL;
    int i;

    push(head, 6);
    push(head, 5);
    push(head, 4);
    push(head, 3);
    push(head, 2);
    push(head, 1);

    cout << "Created Linked List: ";
    printList(head);
    pairwiseSwap(head);
  //rearrange(&head);
    cout << "Swapped Linked List: ";
    printList(head);

  return 0;
}
