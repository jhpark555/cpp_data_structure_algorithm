#include <iostream>
#include <limits>

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

// Recursive function to find the maximum path sum "starting" from the
// given node in a binary tree. The maximum path sum between two nodes
// in a binary tree is updated in the reference variable `result`.

int findMaxPathSum(Node *root, int &result)
{
  if(root == nullptr) return 0;
//printf("#%d  \n",root->data);
  int left = findMaxPathSum(root->left,result);
  //printf("*%d  left=%d\n",root->data,left);
  int right= findMaxPathSum(root->right,result);
  //printf("*%d  right=%d\n",root->data,left);
  //try all possible combination to get the optimal result

  result = max(result,root->data);
  result = max(result,root->data+left);
  result = max(result,root->data+right);
  result = max(result,root->data+left+right);
printf("max=%d \n",result);
  return max(root->data,root->data+max(left,right));
}

int main()
{
  /* Construct the following tree
          1
        /   \
       /     \
      2      10
     / \    /  \
   -1  -4  -5   -6
       /   / \
      3   7   4
           \
           -2
  */

  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(10);
  root->left->left = new Node(-1);
  root->left->right = new Node(-4);
  root->left->right->left = new Node(3);
  root->right->left = new Node(-5);
  root->right->right = new Node(-6);
  root->right->left->left = new Node(7);
  root->right->left->right = new Node(4);
  root->right->left->left->right = new Node(-2);

  int result = numeric_limits<int>::min();
  findMaxPathSum(root, result);
  cout << "The maximum path sum is " << result << endl;

  return 0;
}
