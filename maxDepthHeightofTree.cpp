#include <iostream>
using namespace std;

class Node
{
  public:
    int data;
    Node* left;
    Node *right;
};

int maxDepth(Node *tree)
{
  int lhigh,rhigh;

   if(tree ==nullptr ) return 0;

  lhigh=maxDepth(tree->left);
  rhigh=maxDepth(tree->right);

  if(lhigh > rhigh) return(lhigh+1);
  else return(rhigh+1);
}

Node *newNode(int data)
{
  Node *newnode=new Node();
  newnode->data = data;
  newnode->left= nullptr;
  newnode->right = nullptr;

  return newnode;
}

int main()
{
  Node *root=newNode(1);

  root->left=newNode(2);
  root->right=newNode(3);
  root->left->left=newNode(4);
  root->right->right=newNode(5);

  cout<<"Height is :"<<maxDepth(root);
}
