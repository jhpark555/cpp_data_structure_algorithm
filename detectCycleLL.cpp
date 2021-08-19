#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
};

void push(Node*&headref,int data)
{
  Node *newNode=new Node();

  newNode->data=data;
  newNode->next=headref;
  headref=newNode;
}

bool detectCycle(Node *head)
{
  Node *slow=head;
  Node *fast=head;

  while(fast && fast->next)
  {
    slow=slow->next;
    fast=fast->next->next;
    if(slow==fast){
      cout<<"meet at:  "<<slow->data<<endl;
       return true;
    }
  }
  return false;
}

Node *identifyCycle(Node *head)
{
  Node *slow=head;
  Node *fast=head;

  while(fast && fast->next)
  {
    slow=slow->next;
    fast=fast->next->next;
    if( slow == fast ) return slow;
  }
  return nullptr;
}
void removeCycle(Node *obj,Node* head)
{
  Node *curr=head;
  Node *slow=obj;

  while(slow!=NULL)
  {

    if(curr->next->data == slow->next->data){
      cout<<"\nMeet:"<<curr->next->data<<endl;
      slow->next=nullptr;
    }
    slow=slow->next;
    curr=curr->next;
  }
}
void printList(Node *head)
{
  Node *curr=head;

  while(curr!=NULL)
  {
    cout<<curr->data<<"->";
    curr=curr->next;
  }
  cout<<"nullptr";
}

void moveNode(Node **dst,Node **src)
{
  Node *curr=*src;;

  (*src)=(*src)->next;
  curr->next= *dst;
  *dst=curr;
}

int main()
{
  //int key[]={1,2,3,4,5};
  //int n=sizeof(key)/sizeof(key[0]);
  int n=5;
  int i;

  Node *head=NULL;

  for(i=n+1;i > 0; i--)
  {
    push(head,i);
  }

  head->next->next->next->next->next=head->next;
  if( detectCycle(head)){
    cout<<"Cycle Found";
  }
  else
    cout<<"No cycle Found";
  cout<<endl;
  Node *obj=identifyCycle(head);
  removeCycle(obj,head);
  printList(head);

  //  move Node test code
  Node *dst=NULL;
  while( head!=nullptr){
  moveNode(&dst,&head);
  cout<<" Move node test "<<endl;
  printList(dst);
  }
}
