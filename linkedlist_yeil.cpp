#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct elt {
  struct elt *next;
  int value;
};

typedef struct elt *Stack;

#define STACK_EMPTY  (0)

struct stack {
  struct elt *head;
};

void
stackPush(Stack *s, int value)
{
  struct elt *e;
  e= (struct elt*)malloc(sizeof(*e));
  assert(e);
  e->value = value;
  e->next =*s;
  *s=e;
}
int
stackEmpty(const Stack *s)
{
  return (*s ==0);
}
int
stackPop(Stack *s)
{
  struct elt *e=*s;
//  *s= (*s)->next;
  *s=e->next;
  int ret= e->value;
  free(e);
  return(ret);
}

void
stackPrint(const Stack *s)
{
  struct elt *e=*s;
  while(e !=NULL)
  {
    printf("%d ->",e->value);
    e=e->next;
  }

}

void
stackPrintReversed(Stack *first)
{
  struct elt *curr=*first;

  struct elt *s2;
  s2=(struct elt*)malloc(sizeof(*s2));

  while(curr!=NULL)
  {
    stackPush(&s2,curr->value);
  //  printf("* %d \n",curr->value);
    curr=curr->next;
  }
  //stackPrint(&s2);

}
int
main(int argc, char **argv)
{
  int i;
  Stack s;
  s=STACK_EMPTY;

  for(i=0; i< 5;i++)
  {
    printf("push %d \n",i);
    stackPush(&s,i);
    stackPrint(&s);
  }
  while(!stackEmpty(&s))
  {
    printf("pop gets %d \n",stackPop(&s));
    stackPrint(&s);

  }


  return 0;
}
