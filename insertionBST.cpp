#include <iostream>
using namespace std;

struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
};

Node *newNode(int key)
{
  Node *node = new Node;
  node->data = key;
  node->left=nullptr;
  node->right=nullptr;

  return node;
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

void insert(Node *&root,int key)    // node reference use &
{
  if(root ==nullptr){
    root= newNode(key);
    return;
  }

  if(key < root->data)
      insert(root->left,key);
  else
      insert(root->right,key);
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

#if 1
void deleteNode(Node *&root,int key)
{
  Node *parent =nullptr;
  Node *curr=root;

  searchKey(curr,key,parent);

  if(curr==nullptr) return;

  //1. no child , it's a leaf node
  if(curr->left ==nullptr && curr->right==nullptr)
  {
     if(curr!=root)
     {
       if(parent->left == curr)  parent->left= nullptr;
       else parent->right = nullptr;
     }
     else
     {
       root= nullptr;
     }
     delete curr;
  }
  //2. two child
  else if(curr->left && curr->right)
  {
    Node *successor = minvalueNode(curr->right);
    int val=successor->data;

    deleteNode(root,successor->data);
    curr->data=val;
  }
  //3. one child
  else {
    Node *child = (curr->left)? curr->left:curr->right;

    if(curr!=root)
    {
      if(curr==parent->left)  parent->left=child;
      else parent->right= child;
    }
    else
    {
      root=child;
    }
  }
   delete curr;
}
#else
Node *deleteNode(Node * root,int key)
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
  return root;
}
#endif

int main()
{
  int keys[]={15,10,20,8,12,16,25};
  Node *root= nullptr;

  for( int key: keys)
  {
    insert(root,key);
  }
   cout<<"Original : ";
   inorder(root);
   cout<<endl;
   cout<<"Deleted : ";
   deleteNode(root,16);
   deleteNode(root,12);
   inorder(root);

}
