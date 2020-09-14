/*Author : Dhruvil Patel(DP)*/

#include<bits/stdc++.h>

using namespace std;

struct node{

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

int height(struct node *root)
{


if(root==NULL)
{
  return -1;
}


int l  = height(root->left);
int r = height(root->right);

if(l>r)
{
  return l+1;
}
else{
  return r+1;
}


}


int diameter(struct node *root)
{
  if(root==NULL)
  {
    return 0;
  }

  int x=height(root->left);
  int y=height(root->right);

  int ldiam=diameter(root->left);
  int rdiam=diameter(root->right);

  return(max(x+y+2,max(ldiam,rdiam)));


}



int main()
{
  struct node * root;
  root = create(4);

  root->left = create(3);
  root->right = create(2);
  root->left->left=create(8);
  root->left->left->left=create(9);
  root->left->left->right=create(10);
  root->right->left=create(7);
  root->right->right=create(5);

cout<<diameter(root);

}
