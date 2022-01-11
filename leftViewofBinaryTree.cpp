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
    left= nullptr;
    right= nullptr;
  }
}Node;

void leftViewPrint(Node *root,int curr_level,int *max_level)
{
  if(root ==nullptr) return;

  if(curr_level > *max_level)
  {
    printf("%d ",root->data);
    *max_level=curr_level;
  }

  leftViewPrint(root->left,curr_level+1,max_level);
  leftViewPrint(root->right,curr_level+1,max_level);
}

void leftView(Node *root)
{
  int max_level=0;

  leftViewPrint(root,1,&max_level);

}

void leftViewLevelOrder(Node *root)
{
  if(root==nullptr) return;

  queue<Node *>que;
  que.push(root);

  while(!que.empty())
  {
    int p=que.size();
    //printf("\n++++p=%d \n",p); //pjh
    for(int i=1;i <=p; i++)
    {
      Node *temp=que.front();
      if( i==1) printf("%d ",temp->data);

      if(temp->left) que.push(temp->left);
      if(temp->right) que.push(temp->right);

      que.pop();
    }
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

    /* Calling function to print left view of binary tree */
    cout<<"The Left View of Binary Tree is:\n";
  //  leftView(root);
  leftViewLevelOrder(root);     //level order view method
}
