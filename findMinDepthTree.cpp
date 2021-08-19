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
    this->left=this->right=nullptr;
  }
};

int findMinDepth(Node *root)
{
   if( root ==nullptr) return 0;

   int l= findMinDepth(root->left);
   int r= findMinDepth(root->right);

  // printf("%d \n",root->data);
   if(root->left ==nullptr)
     return 1+r;
   if( root->right ==nullptr)
     return 1+l;

    return min(l,r) +1;
}

int main()
{
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);
  root->left->left->right = new Node(8);
  root->left->right->right = new Node(9);
  root->right->right->left = new Node(10);
  root->right->right->left = new Node(11);
  root->left->left->right->right = new Node(12);

  cout << "The minimum depth is " << findMinDepth(root);

}
