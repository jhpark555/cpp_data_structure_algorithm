#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *left;
  struct node *right;
};

void insertElement(struct node **tree,int val)
{
  struct node *newNode=(struct node *)malloc(sizeof(struct node));
  struct node *curr=*tree;
  struct node *parent=NULL;

  newNode->data=val;
  newNode->left=NULL;
  newNode->right=NULL;

  if( (*tree)== NULL)
  {
    (*tree)=newNode;
    (*tree)->left=NULL;
    (*tree)->right=NULL;
  }
  else
  {
     while(curr!=NULL)
     {
       parent=curr;
       if(val < curr->data) curr=curr->left;
       else curr=curr->right;
     }
    if(val<parent->data) parent->left=newNode;
    else parent->right=newNode;
  }
  //return tree;
}

void preorderTraverse(struct node *tree)
{
  if(tree!=NULL)
  {
    printf("%d \t",tree->data);
    preorderTraverse(tree->left);
    preorderTraverse(tree->right);
  }
}

void inorderTraverse(struct node *tree)
{
  if(tree!=NULL)
  {
    inorderTraverse(tree->left);
    printf("%d \t",tree->data);
    inorderTraverse(tree->right);
  }
}
int main()
{
 struct node *tree=NULL;

  insertElement(&tree,50);
  insertElement(&tree,30);
  insertElement(&tree,20);
  insertElement(&tree,40);
  insertElement(&tree,70);
  insertElement(&tree,60);
  insertElement(&tree,80);


 preorderTraverse(tree);   printf("\n");
 inorderTraverse(tree);

}
