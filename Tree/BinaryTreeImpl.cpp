//Author: Dhruvil Patel(DP)

#include<bits/stdc++.h>

using namespace std;


struct node{

int data;
struct node *left;
struct node *right;

};


struct node * create(int x)
{
  if(x==-1)
  {
    return NULL;
  }

  struct node *newnode = new node;

  newnode->data=x;

  int xx;
  cout<<"Enter the data for left node\n";
  cin>>xx;

  newnode->left = create(xx);

  cout<<"Enter the data for right node\n";
  cin>>xx;

  newnode->right=create(xx);

  return newnode;

}

void print(struct node *root)
{
  if(root==NULL)
  {
    return;
  }
  cout<<(root->data)<<" ";
  print(root->left);
  print(root->right);
}



int main()
{
struct node *root=NULL;

int xx;
cout<<"Enter the data for root node\n";
cin>>xx;
if(xx!=-1){
root = create(xx);
}

print(root);

  return 0;
}
