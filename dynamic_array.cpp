#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>

struct array{
  size_t n;
  size_t size;
  int *data;
};

struct array *arrayCreate(void);
int arrayGet(struct array *,size_t position);
int arraySet(struct array *,size_t position, int value);
void arrayDestroy(struct array *);

#define SIZE_INITIAL (3)
#define SIZE_MULTIPLIER  (2)

struct array * arrayCreate(void)
{
  struct array *a=(struct array *)malloc(sizeof(struct array));
  assert(a);

  a->size=SIZE_INITIAL;
  a->data=(int *)calloc(a->size,sizeof(int));
  assert(a->data);

  return a;
}

static void arrayExpand(struct array *a,size_t position)
{
  if(position >=a->size){
    int bigger = a->size *SIZE_MULTIPLIER;
    if(position >=bigger){
      bigger = position +1;
    }

    a->data=(int *)realloc(a->data,sizeof(int)*bigger);
    memset(&a->data[a->size],0,sizeof(int)*(bigger-a->size));

    a->size=bigger;
  }
}

int arrayGet(struct array *a,size_t position)
{
  if(position >=a->size){
    return 0;
  }
  else {
    return a->data[position];
  }
}
int arraySet(struct array *a,size_t position, int value)
{
  arrayExpand(a,position);
  return a->data[position]=value;
}

void arrayDestroy(struct array *a)
{
  free(a->data);
  free(a);
}

int main(int argc,char **argv)
{
   struct array *A;
   A=arrayCreate();
   arraySet(A,0,10);
   arraySet(A,1,20);
   arraySet(A,2,30);
   arraySet(A,3,40);

   int r= arrayGet(A,0);
   printf("get= %d \n",r);

  return 0;
}
