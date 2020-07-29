//Author:Dhruvil Patel(DP)

#include<bits/stdc++.h>

using namespace std;

struct node {

  int data;
  struct node *left;
  struct node *right;

};

struct node * addNode(int x)
{
  struct node *newnode = new struct node;
  newnode->data=x;
  newnode->left=NULL;
  newnode->right=NULL;

  return newnode;
}


void path(struct node *root,vector<int> v)
{
    if(root->left==NULL && root->right==NULL)
    {
      v.push_back(root->data);
      for(auto x:v)
      {
        cout<<x<<" ";
      }
      cout<<endl;
      return;
    }

    v.push_back(root->data);

    path(root->left,v);
    path(root->right,v);



}




int main()
{

  struct node *root = addNode(30);
  root->left=addNode(10);
  root->left->left=addNode(3);
  root->left->right=addNode(16);
  root->right=addNode(50);
  root->right->left=addNode(40);
  root->right->right=addNode(60);

  vector<int> v;
  path(root,v);



  return 0;
}
