#include<bits/stdc++.h>
using namespace std;

typedef struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
  Node(int ele)
  {
    data=ele;
    left=nullptr;
    right=nullptr;
  }
}Node;

void preorder(Node *root)
{
  if(root ==nullptr) return;
  printf("%d ",root->data);
  preorder(root->left);
  preorder(root->right);
}
void inorder(Node *root)
{
  if(root==nullptr) return;
  inorder(root->left);
  printf("%d ",root->data);
  inorder(root->right);
}
void postorder(Node *root)
{
  if(root ==nullptr) return;
  postorder(root->left);
  postorder(root->right);
  printf("%d ",root->data);
}

void printleafnode(Node *root)
{
  if(root==nullptr) return;
  if(root->left ==nullptr && root->right==nullptr)
  {
    printf("%d ",root->data);
    return;
  }
  printleafnode(root->left);
  printleafnode(root->right);
}
int countnode(Node *root)
{
  static int count = 1;

  if(root==nullptr) return 0;

  if(root->left !=nullptr){
    count++;
    countnode(root->left);
   }
  if(root->right !=nullptr){
    count++;
    countnode(root->right);
  }
  return count;
}

int height(Node *root)
{
  if(root==nullptr) return 0;
  int leftheight= height(root->left);
  int rightheight= height(root->right);

  return max(leftheight,rightheight) +1;   // plus 1 oer every next step
}

void printlevel(Node *root, int level)
{
  if(root ==nullptr) return ;

  if(level==1)    printf("%d ",root->data);
  else{
    printlevel(root->left,level-1);
    printlevel(root->right,level-1);
  }
}

void printalternative(Node *root)
{
  if( root ==nullptr) return;

  int l=height(root);

  for(int i=1;i<l;i+=2)
  {
    printlevel(root,i);
  }
}

int main(void)
{
  /* Creating a Binary tree and inserting some nodes in it */
 Node *root = new Node(1);
 root -> left = new Node(2);
 root -> right = new Node(3);
 root -> left -> left = new Node(4);
 root -> left -> right = new Node(5);
 root -> right -> left = new Node(6);
 root -> right -> right = new Node (7);
 root -> right -> right ->right = new Node (10);
 root -> left -> right -> left = new Node(8);
 root -> right -> left -> right = new Node(9);

 /* Traversing Tree in Preorder, Inorder and Postorder Form */

  /* Preorder Traversal */
  cout<<"The Preorder Traversal is:\n";
  preorder(root);
  cout<<endl;

  /* Inorder Traversal */
  cout<<"The Inorder Traversal is:\n";
  inorder(root);
  cout<<endl;

  /* Postorder Traversal */
  cout<<"The Postorder Traversal is:\n";
  postorder(root);
  cout<<endl;
  printf("Leaf Node:");
  printleafnode(root);
  printf("\n");
  printf("Countnode : %d",countnode(root));
  printf("\n");
  printf("height : %d",height(root));
  printf("\n");
  printf("Alternative : ");
  printalternative(root);

}
