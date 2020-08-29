//Author:Dhruvil Patel(DP)

#include<bits/stdc++.h>

using namespace std;

struct node {

  int data;
  struct node *left;
  struct node *right;

};


struct node * create(int x)
{

  struct node * newnode = new struct node;
  newnode->data = x;
  newnode->left=NULL;
  newnode->right=NULL;

  return newnode;
}

void insert(struct node *root,int x)
{

if(root==NULL)
{
  struct node *newnode=create(x);
  return;
}

while(1)
{
  if(x>root->data)
  {
    if(root->right==NULL)
    {
      struct node *newnode = create(x);
      root->right=newnode;
      return;
    }
    root=root->right;
  }

  if(x<root->data)
  {
    if(root->left==NULL)
    {
      struct node *newnode=create(x);
      root->left=newnode;
      return;
    }
    root=root->left;
  }
}

}







void inorder(struct node *root)
{
  if(root==NULL)
  {
    return;
  }

  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);

}

int main()
{
  struct node *root=NULL;
  root=create(10);
  insert(root,13);
  insert(root,4);
  insert(root,5);
  insert(root,40);
  insert(root,23);
  insert(root,15);
  insert(root,3);
  insert(root,12);

  inorder(root);
  cout<<endl;

  deletenode(&root,12);
  inorder(root);
  cout<<endl;

  return 0;
}
