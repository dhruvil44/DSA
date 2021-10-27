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


struct node* deletenode(struct node* root, int key) {

  if(root==NULL) {
    return NULL;
  }

  if(root->data==key) {

    //if its a leaf node
    if(root->left==NULL and root->right==NULL) {
      return NULL;
    }

    //if only left subtree is present
    if(root->left and !root->right) {
      return root->left;
    }

    //if only right subtree is present
    if(root->right and !root->left) {
      return root->right;
    }

    if(root->left and root->right) {
      struct node* temp = root->left;
      while(temp->right) {
        temp = temp->right;
      }

      int d = temp->data;
      temp->data = root->data;
      root->data = d;

      root->left = deletenode(root->left, temp->data);

    }

  }

  if(root->data > key) {
    root->left = deletenode(root->left, key);
  }

  if(root->data < key) {
    root->right = deletenode(root->right, key);
  }

  return root;
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

  root = deletenode(root,12);
  inorder(root);
  cout<<endl;

  return 0;
}
