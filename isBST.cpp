#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *left;
  Node *right;

  Node(int data)
  {
    this->data = data;
    this ->left =nullptr;
    this->right =nullptr;
  }
};


int maxValue( Node *root)
{
   Node *curr=root;
  while(curr!=nullptr && curr->right!=nullptr)
  {
    curr=curr->right;
  }
  //printf("max=%d \n",curr->data);
  return curr->data;
}

int minValue( Node *root)
{
  Node *curr=root;
  while( curr!=nullptr && curr->left !=nullptr)
  {
    curr=curr->left;
  }
//printf("min=%d \n",curr->data);
  return curr->data;
}

int isBST( Node *root)
{
  if(root == nullptr)
  return 1;

  if(root->left !=nullptr && maxValue(root->left) > root->data)
    return 0;
  if(root->right !=nullptr && minValue(root->right) < root->data)
    return 0;

  if( !isBST(root->left) || !isBST(root->right))
    return 0;

return 1;

}


int main()
{
  Node *root = new Node(4);
  root->left = new Node(2);
  root->right = new Node(5);
  root->left->left = new Node(1);
  root->left->right = new Node(3);

  if(isBST(root))
    cout<<"Is Bst";
  else
    cout<<"Not a BST";

  return 0;
}
