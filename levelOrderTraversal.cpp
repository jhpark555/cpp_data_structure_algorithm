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

int height(Node *root)
{
  if( root ==nullptr){
   return 0;
 }
  else{
     int leftheight=height(root->left);
     int rightheight=height(root->right);
    // printf(" l=%d r=%d \n",leftheight,rightheight);
     return max(leftheight,rightheight) +1 ;
 }
}
void printlevel(Node *root,int level)
{
  if(root ==nullptr ) return;

  if( level==1) printf("%d ",root->data);
  else if(level > 1)
  {
    printlevel(root->left, level-1);
    printlevel(root->right,level-1);
  }
}

void levelOrder(Node *root)
{
  if(root ==nullptr) return;

  int h=height(root);
  for(int i=1; i <= h; i++)
   printlevel(root,i);
}

void Traverse(Node *root)
{
  queue<Node*> q;
  if(root !=nullptr) q.push(root);

  while(!q.empty())
  {
    Node *u=q.front();
    printf("%d ",u->data);
    if(u->left !=nullptr) q.push(u->left);
    if(u->right !=nullptr) q.push(u->right);
    q.pop();
  }

}
int main()
{
    /* Creating a Binary tree and inserting some nodes in it */
    Node *root = NULL;

    root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> right -> left = new Node(6);
    root -> right -> right = new Node (7);
    root -> left -> right -> left = new Node(8);
    root -> right -> left -> right = new Node(9);

  //printf("H= %d ",  height(root));
    /* Calling function for Level Order Traversal */
    cout<<"The Level Order Traversal of the Given Binary Tree is:\n";
  //  levelOrder(root);
  Traverse(root);
}
