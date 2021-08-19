//https://www.techiedelight.com/construct-height-balanced-bst-from-unbalanced-bst/


#include <iostream>
#include <vector>
using namespace std;

struct Node
{
  int data;
  Node *left;
  Node *right;
  Node( int data)
  {
    this->data=data;
    this->left=this->right= nullptr;
  }
};

void preorder(Node *root)
{
  if(root !=nullptr)
  {
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
  }
}

Node *buildBalancedBST(vector<Node*>&nodes, int start, int end)
{
  if(start > end)
  {
    return nullptr;
  }

  int mid = (start +end) /2;

  //the root node will be a node present at the mid index
  Node *root = nodes[mid];

  //recursively constant left and right subtrees
  root->left = buildBalancedBST(nodes, start, mid-1);
  root->right = buildBalancedBST(nodes, mid+1, end);

  return root;
}

//inorder style push_back  node data
void pushTreeNodes(Node *root,vector<Node *>&nodes)
{
  if(root == nullptr)  return;
  pushTreeNodes(root->left,nodes);
  nodes.push_back(root);
  pushTreeNodes(root->right,nodes);

}

void constructBalancedBST(Node *&root)
{
   //push nodes of a given bst into a vector in sorted Inorder
   vector<Node *>nodes;
   pushTreeNodes(root,nodes);

   //construct a height balanced bst from sorted nodes
   root = buildBalancedBST(nodes, 0 ,nodes.size() -1);
}


int main()
{
  Node* root = new Node(20);
  root->left = new Node(15);
  root->left->left = new Node(10);
  root->left->left->left = new Node(5);
  root->left->left->left->left = new Node(2);
  root->left->left->left->right = new Node(8);

  constructBalancedBST(root);

  cout << "Preorder traversal of the constructed BST is ";
  preorder(root);

  return 0;
}
