#include <iostream>

using namespace std;

class Node
{
public:
  char data;
  Node *left;
  Node *right;
};

Node *newNode(char data)
{
  Node *node = new Node();
  node->data=data;
  node->left=nullptr;
  node->right=nullptr;

  return node;
}

printInorder(Node *node)
{
  if(node!=nullptr)
  {
    printInorder(node->left);
    cout<<node->data<<" ";
    printInorder(node->right);
  }
}

int search(char arr[],int start,int end,char data)
{
  int i;
  for(i= start;i<end; i++)
  {
    if(arr[i]==data) return i;
  }
}

Node *buildTree(char in[],char pre[],int start,int end)
{
  static int preIndex=0;
  if(start > end) return nullptr;

  Node *tNode=newNode(pre[preIndex++]);
//printf("%c-> ",tNode->data);
  int inDex=search(in,start,end,tNode->data);
//printf("%d-> ",inDex);
  tNode->left=buildTree(in,pre,start,inDex-1);
  tNode->right=buildTree(in,pre,inDex+1,end);

}

int main()
{
  char in[]={'D','B','E','A','F','C'};
  char pre[]={'A','B','D','E','C','F'};

  int len=sizeof(in)/sizeof(in[0]);
  Node *root= buildTree(in,pre,0,len-1);

  cout<<"Inorder traversal of the constructed trees is\n";
  printInorder(root);

  return 0;
}
