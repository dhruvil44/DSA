//Author: Dhruvil Patel(DP)

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

int depth(struct node *root,int x,int d)
{

  if(root==NULL)
  {
    return -1;
  }

  if(root->data==x)
  {
    return d;
  }

  int leveldown = depth(root->left,x,d+1);
  if(leveldown!=-1)
  {
    return leveldown;
  }

  leveldown = depth(root->right,x,d+1);

  if(leveldown!=-1)
  {
    return leveldown;
  }


}

int height(struct node *root)
{


if(root==NULL)
{
  return 0;
}


int l  = height(root->left);
int r = height(root->right);

return 1+max(l,r);
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

  cout<<depth(root,5,0);
  cout<<endl;

  cout<<height(root);
  cout<<endl;



  return 0;
}
