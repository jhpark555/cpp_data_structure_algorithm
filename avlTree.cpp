#include <iostream>
using namespace std;

struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
  int height;
};

Node *newNode(int key)
{
  Node *node = new Node;
  node->data = key;
  node->left=nullptr;
  node->right=nullptr;
  node->height= 1;

  return node;
}

int height(Node *root)
{
   if(root ==nullptr ) return 0;

   return root->height;
}

int getbalance(Node *root)
{
  if(root ==nullptr ) return 0;

  return ( height(root->left)-height(root->right));
}
void inorder(Node *tree)
{
  if(tree!=nullptr)
  {
    inorder(tree->left);
    cout<<tree->data<<" ";
    inorder(tree->right);
  }
}

void preorder(Node *tree)
{
  if(tree !=nullptr)
  {
    cout<<tree->data<<" ";
    preorder(tree->left);
    preorder(tree->right);
  }
}

//     y                               x
//    / \     Right Rotation          /  \
//   x   T3   - - - - - - - >        T1   y
//  / \       < - - - - - - -            / \
// T1  T2     Left Rotation            T2  T3

Node *rightrotate(Node *y)
{
   Node *x=y->left;
   Node *T2=x->right;

   x->right=y;
   y->left=T2;
   y->height = max(height(y->left),height(y->right))+1;
   x->height = max(height(x->left),height(x->right))+1;

   return x;
}

Node *leftrotate(Node *x)
{
   Node *y=x->right;
   Node *T2=y->left;

   y->left= x;
   x->right= T2;
   x->height = max(height(x->left),height(x->right))+1;
   y->height = max(height(y->left),height(y->right))+1;

   return y;
}


Node *insert(Node *root,int key)    // node reference use &
{
  if(root ==nullptr){
    return newNode(key);
  }

  if(key < root->data)
      root->left=insert(root->left,key);
  else if(key > root->data)
      root->right=insert(root->right,key);
  else
      return root;

// after insert like BST, below is for checking balance and rotation for AVL tree.
   root->height = max( height(root->left), height(root->right)) +1 ;

   int balance = getbalance(root);

   //left left case
//  T1, T2, T3 and T4 are subtrees.
//         z                                      y
//        / \                                   /   \
//       y   T4      Right Rotate (z)          x      z
//      / \          - - - - - - - - ->      /  \    /  \
//     x   T3                               T1  T2  T3  T4
//   / \
//  T1   T2
   if(balance >1 && key < root->left->data)   //right rotation
     return ( rightrotate(root));     // based on 'z'
     // Right Right Case
   //  z                                y
   // /  \                            /   \
   //T1   y     Left Rotate(z)       z      x
   //    /  \   - - - - - - - ->    / \    / \
   //   T2   x                     T1  T2 T3  T4
   //       / \
   //     T3  T4

   if(balance <-1 && key > root->right->data)
    return ( leftrotate(root));

    // Left Right Case

  //    z                               z                           x
  //   / \                            /   \                        /  \
  //  y   T4  Left Rotate (y)        x    T4  Right Rotate(z)    y      z
  // / \      - - - - - - - - ->    /  \      - - - - - - - ->  / \    / \
 //T1   x                          y    T3                    T1  T2 T3  T4
 //    / \                        / \
 //  T2   T3                    T1   T2
  if(balance >1 && key> root->left->data)
  {
     root->left=leftrotate(root->left);    //based on 'y'
     return(rightrotate(root));          //based on 'z'
   }
   // Right Left Case
//   z                            z                            x
//  / \                          / \                          /  \
//T1   y   Right Rotate (y)    T1   x      Left Rotate(z)   z      y
//    / \  - - - - - - - - ->     /  \   - - - - - - - ->  / \    / \
//   x   T4                      T2   y                  T1  T2  T3  T4
//  / \                              /  \
//T2   T3                           T3   T4
  if( balance <-1 && key < root->right->data)
  {
    root->right= rightrotate(root->right);   // based on 'y'
    return ( leftrotate(root));    //based on 'z'
  }

  return root;

}
Node *minvalueNode(Node *root)
{
   Node *curr=root;

   while(curr->left !=nullptr)
   {
     curr=curr->left;
   }
  return curr;
}


void searchKey(Node *&root,int key, Node *&parent)
{
   Node *&curr=root;
   while(curr !=nullptr && curr->data!=key)
   {
     parent= curr;

     if(key < curr->data)
       curr=curr->left;
     else
       curr=curr->right;
   }
   cout<<"\tSearched :"<<curr->data<<endl;
}

Node *deleteNode(Node *root,int key)
{
  if( root ==nullptr) return nullptr;

  if( key< root->data)      root->left= deleteNode(root->left,key);
  else if(key > root->data)  root->right= deleteNode(root->right,key);
  else
  {
   //1. chile is single or no
    if( root->left == nullptr) {
      Node *temp=root->right;
      delete root;
      return temp;
    }
    else if( root->right ==nullptr){
      Node *temp=root->left;
      delete root;
      return temp;
    }

   //2. chile is two
   else {
    Node *temp=minvalueNode(root->right);
    root->data=temp->data;
    root->right= deleteNode(root->right,temp->data);
   }
  }
  // check for AVL tree
  root->height =max( height(root->left),height(root->right))+1;

  int balance = getbalance(root);

  if(balance > 1 && key< root->left->data)
   return rightrotate(root);

  if(balance <-1 && key > root->right->data)
   return  leftrotate(root);

  if(balance > 1 && key> root->right->data)
  {
     root->left=leftrotate(root->left);
     return rightrotate(root);
  }

  if(balance < -1 && key < root->right->data)
  {
     root->right=rightrotate(root->right);
     return leftrotate(root);
  }


  return root;
}

int main()
{
  int keys[]={10,20,30,40,50,25};
  Node *root= nullptr;

  for( int key: keys)
  {
    root=insert(root,key);
  }
   cout<<"Original : ";
   preorder(root);
   cout<<endl;
   cout<<"Deleted : ";
   deleteNode(root,50);
   preorder(root);

}
