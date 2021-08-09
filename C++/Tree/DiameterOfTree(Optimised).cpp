//Author:Dhruvil Patel

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

class Pair{
public:
  int height;
  int diameter;
};

Pair diameter_optimised(node* root) {

  Pair p;
  if(root==NULL) {
    p.height=0;
    p.diameter=0;
    return p;
  }

  Pair left = diameter_optimised(root->left);
  Pair right = diameter_optimised(root->right);

  p.height = max(left.height,right.height)+1;
  p.diameter = max({left.height+right.height , left.diameter, right.diameter});

  return p;
}

int main() {

  struct node * root;
  root = create(4);

  root->left = create(3);
  root->right = create(2);
  root->left->left=create(8);
  root->left->left->left=create(9);
  root->left->left->right=create(10);
  root->right->left=create(7);
  root->right->right=create(5);

  Pair p = diameter_optimised(root);
  cout<<p.height<<endl;
  cout<<p.diameter<<endl;
  return 0;
}
