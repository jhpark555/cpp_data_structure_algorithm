#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct elt{
  struct elt *next;
  int value;
};

struct queue{
  struct elt *head;
  struct elt *tail;
};

struct queue *
queueCreate(void)
{
  struct queue *q;
  q=(struct queue*)malloc(sizeof(*q));
  q->head = q->tail =NULL;
  return q;
}
void
enq(struct queue *q,int value)
{
  struct elt *e;
  e=(struct elt*)malloc(sizeof(*e));
  assert(e);

  e->value= value;
  e->next=0;

  if(q->head ==0){
    q->head = e;
  }
  else {
    q->tail->next=e;
  }
  q->tail=e;
}

int
queueEmpty(const struct queue *q)
{
  return ( q->head ==0);
}
int
deq(struct queue *q)
{
  struct elt *e;
  int ret;

  e= q->head;
  ret=q->head->value;
  q->head=q->head->next;
  free(e);

  return (ret);
}
void
queuePrint(struct queue *q)
{
  struct elt *e=q->head;

  while(e!=NULL){
    printf("%d->",e->value);
    e=e->next;
  }
}
void
queueDestroy(struct queue *q)
{
  while(!queueEmpty(q)){
    deq(q);
  }
}
int
main(int argc,char **argv)
{
  int i;
  struct queue *q;
  q=queueCreate();

  for(i=0;i< 5;i ++)
  {
    printf("enq %d \n",i);
    enq(q,i);
    queuePrint(q);
  }

  while(!queueEmpty(q))
  {
    printf("deq gets %d \n",deq(q));
    queuePrint(q);
  }

  queueDestroy(q);
}
