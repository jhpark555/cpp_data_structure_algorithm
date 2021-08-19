#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *left;
  Node *right;
  Node(int data)
  {
    this->data=data;
    this->left=nullptr;
    this->right=nullptr;
  }
};

void preorder(Node *root)
{
  if(root!=nullptr)
  {
    cout<< root->data<<' ';
    preorder(root->left);
    preorder(root->right);
  }
}

int findChildrenSum(Node *root)
{

  if(root!=nullptr && (root->left!=nullptr || root->right!=nullptr))
   return root->left->data + root->right->data;
  else
   return 0;
}

void fixBinaryTree(Node *root)
{
  if(root==nullptr || root->left==nullptr &&root->right==nullptr)
     return;
 //printf("%d  \n",root->data);
  fixBinaryTree(root->left);
  fixBinaryTree(root->right);

  //calculate diffeence between root and childere.
  int diff = root->data -findChildrenSum(root);
  //printf("*diff=%d \n",diff);
  if(diff < 0) {
    root->data +=abs(diff);
  }

  else if(diff >0)
  {
    Node *subtree = root->left? root->left:root->right;
    subtree->data +=diff;
    fixBinaryTree(subtree);
  }

}


int main()
{
  Node *root= new Node(25);
  root->left= new Node(8);
  root->right= new Node(10);
  root->left->left = new Node(4);
  root->left->right= new Node(5);
  root->right->left= new Node(6);
  root->right->right= new Node(7);

  fixBinaryTree(root);
  preorder(root);
}
