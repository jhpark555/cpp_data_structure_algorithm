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

void maxWidth(Node *root)
{
  if(root ==nullptr) return;

  // create queue and root node
  queue<Node *>que;
  que.push(root);

  int maxWidth =0;

  while(!que.empty())
  {
    int currSize =que.size();
    maxWidth = max(maxWidth,currSize);
  //  printf("%d \n",currSize);
    for(int i=1; i<=currSize; i++)
    {
      Node *temp=que.front();
    //  printf("\n*%d \n",temp->data);
      que.pop();
      if(temp->left) que.push(temp->left);
      if(temp->right) que.push(temp->right);
    }
  }
  printf("%d ",maxWidth);
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

    /* Calling function to Compute maximum width of Binary Tree*/
    cout<<"The Maximum Width of the Given Binary Tree is: ";
    maxWidth(root);
}
