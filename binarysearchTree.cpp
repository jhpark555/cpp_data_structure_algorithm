#include <iostream>
using namespace std;

struct node
{
  int data;
  struct node *left;
  struct node *right;
};

node *NewNode(int data)
{
  node *newNode= new node;
  newNode->data=data;
  newNode->left=newNode->right=nullptr;

  return newNode;
}

void insertElement(node **tree,int val)
{
  node *newNode= NewNode(val);

  if(*tree==nullptr)
  {
    (*tree)=newNode;
    (*tree)->left=NULL;
    (*tree)->right=NULL;
  }
  else{
    if(val < (*tree)->data )   insertElement(&(*tree)->left,val);
    else insertElement(&(*tree)->right,val);
  }
}

void preorderTraverse(node *tree)
{
  if(tree!=NULL)
  {
    printf("%d \t",tree->data);
    preorderTraverse(tree->left);
    preorderTraverse(tree->right);
  }
}

void inorderTraverse(node *tree)
{
  if(tree!=NULL)
  {
    inorderTraverse(tree->left);
    printf("%d \t",tree->data);
    inorderTraverse(tree->right);
  }
}
void postorderTraverse(node *tree)
{
  if(tree!=NULL)
  {
    postorderTraverse(tree->left);
    printf("%d \t",tree->data);
    postorderTraverse(tree->right);
  }
}

int height(node *tree)
{
  int leftheight, rightheight;
  if(tree == nullptr) return 0;
  else
  {
    leftheight= height(tree->left);
    rightheight= height(tree->right);

    if(leftheight > rightheight)  return( leftheight +1);
    else return ( rightheight +1);
  }
}


node *minvalueNode(node *tree)
{
  node *curr=tree;

  while(curr!=nullptr && curr->left!=nullptr)
  {
    curr=curr->left;
  }
  //printf("@min=%d \n",curr->data);
  return curr;
}

node *maxvalueNode(node *tree)
{
  node *curr=tree;
  while(curr!=nullptr && curr->right!=nullptr)
  {
    curr=curr->right;
  }
    //printf("@max=%d \n",curr->data);
  return curr;
}

node *findsmallestElement(node *tree)
{
  if(tree==nullptr ||tree->left ==nullptr)  return tree;
  else
  {
    return  findsmallestElement(tree->left);
  }
}

node *findlargestElement(node *tree)
{
  if(tree==nullptr || tree->right==nullptr)  return tree;
  else
  {
     return  findlargestElement(tree->right);
  }
}

node *deleteElement(node **tree,int val)
{
   if(*tree==nullptr) return *tree;

   if(val<(*tree)->data)          (*tree)->left= deleteElement(&(*tree)->left,val);
   else if( val>(*tree)->data)    (*tree)->right= deleteElement(&(*tree)->right,val);
   else
   {
      // node with only one child or no child
     if((*tree)->left == nullptr)      // tree will be deleted
     {
         node *temp=(*tree)->right;
         free(*tree);
         return temp;
     }
     else if((*tree)->right ==nullptr)
     {
       node *temp=(*tree)->left;
       free(*tree);
       return temp;
     }
     // node with two children:
     // Get the inorder successor
     // (smallest in the right subtree)
     //printf("*****%d \n",(*tree)->data);
     node *temp=minvalueNode((*tree)->right);

     // Copy the inorder
     // successor's content to this node
     (*tree)->data=temp->data;
    // printf("*****%d \n",(*tree)->data);

     (*tree)->right= deleteElement(&(*tree)->right,temp->data);

   }
    return *tree;
}

int minValue(node *tree)
{
    node *current= tree;

    while(current->left !=NULL){
        current=current->left;
    }
 //printf("**min=%d \n",current->data);
    return(current->data);

}

int maxValue(node* tree)
{
    node* current=tree;

    while(current->right !=NULL){
        current=current->right;
    }

    //printf("**max=%d \n",current->data);

    return(current->data);
}

bool isBST(node *tree)
{
  if(tree== nullptr) return true;

  //node *min=minvalueNode(tree->left);
  //node *max= maxvalueNode(tree->right);
  //printf("Min=%d max=%d \n",min->data,max->data);

  //if(tree->left !=nullptr && (min->data > tree->data))  return false;
  //if(tree->right !=nullptr && (max->data < tree->data)) return false;
 if(tree->left !=nullptr && minValue(tree->left) > tree->data)  return false;
 if(tree->right !=nullptr && maxValue(tree->right) < tree->data) return false;

  if(!isBST(tree->left) || !isBST(tree->right)) return true;

  return true;
}

int main()
{
 node *tree=NULL;
 node *ret=nullptr;

  insertElement(&tree,50);
  insertElement(&tree,30);
  insertElement(&tree,20);
  insertElement(&tree,40);
  insertElement(&tree,70);
  insertElement(&tree,60);
  insertElement(&tree,80);

 cout<<"Preorder Traverse :";
 preorderTraverse(tree);   cout<<endl;
 cout<<"Inorder Traverse :";
 inorderTraverse(tree);
 cout<<"Height : "<<height(tree)<<endl;
 cout<<"smallest element :";
 ret=  findsmallestElement(tree);
 cout<<ret->data<<endl;
 cout<<"largest element :";
 ret=  findlargestElement(tree);
 cout<<ret->data<<endl;

 ret= deleteElement(&tree,70);
 cout<<"after delete :";
 inorderTraverse(tree);

 cout<<"Is this BST: "<<isBST(tree)<<endl;

}
