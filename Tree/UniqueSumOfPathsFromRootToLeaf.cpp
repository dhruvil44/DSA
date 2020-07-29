//Author:Dhruvil Patel(DP)

#include<bits/stdc++.h>

using namespace std;


struct node {

  int data;
  struct node *left;
  struct node *right;
};

struct node* addNode(int x)
{

    struct node* newnode
        = (struct node*)malloc(
            sizeof(struct node));

    // Assign data to val variable
    newnode->data = x;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
};

void sums (struct node *root,vector<int> &v,int s)
{

  if(root->left==NULL && root->right==NULL)
  {
    v.push_back(s+root->data);
    return;
  }

  sums(root->left,v,s+root->data);

  sums(root->right,v,s+root->data);

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
sums(root,v,0);

for(auto x:v)
{
  cout<<x<<" ";
}


  return 0;
}
