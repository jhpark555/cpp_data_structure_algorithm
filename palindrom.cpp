/* using stack for saving original head list
onece reverse listed, its original head was reversed so we need to save in stack
for later compare it with original
*/


#include <iostream>
using namespace std;

class Node{
public:
  char data;
  Node *next;
};


struct stack{
  char item[5];
  int ptr;
  int max;
};

void push(Node *&headref,char data)
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
    printf("%c ->",head->data);
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

bool isPalindrom(stack *p,Node *rev)
{
   Node *ret=rev;
   int i=0;
   int j=0;
//for(i=0;i<p->ptr;i++) printf("%c ",p->item[i]);
   //i=p->max;

   while(ret!=NULL && i++<p->max/2)
   {
     printf("@ %c %c\n",p->item[j],ret->data);
     if(p->item[j] !=ret->data)  return false;
    j++;
     ret=ret->next;
   }
  return true;
}


void saveList(Node *head ,stack *v)
{
  Node *curr=head;
  while(curr!=NULL)
  {
     v->item[v->ptr++] = curr->data;
     curr=curr->next;
  }
  v->max=v->ptr;
}
int main()
{
    Node *head=NULL;
    stack s,*p;
    p=&s;
    p->ptr=0;
    int i;

    push(head, 'A');
    push(head, 'B');
    push(head, 'C');
    push(head, 'B');
    push(head, 'A');

    cout << "Created Linked List: ";
    printList(head);
    saveList(head,p);

    Node *rev=  reverseList(head);  printf("\n");

    cout<<"Palindrom:"<<isPalindrom(p,rev)? true:false;


  return 0;
}
