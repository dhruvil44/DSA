//Author: Dhruvil Patel

#include <bits/stdc++.h>
using namespace std;

//Given a Binary Tree.
//Check if its a valid BST or NOT.

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


                                  //the range in between the node should lie
bool is_valid_bst(struct node* root, int minVal, int maxVal) {

  if(!root) {
    return true;
  }

  //if the current node lies outside the range
  if(root->data < minVal || root->data > maxVal) {
    return false;
  }

  //while going left the range becomes [minVal, root->data]
  bool left = is_valid_bst(root->left, minVal, root->data);

  //while going right the range become [root->data, maxVal]
  bool right = is_valid_bst(root->right,root->data,maxVal);

  if(!left || !right) {
    return false;
  }

  return true;
}

int main() {

  struct node * root;
  root = create(10);

  root->left = create(4);
  root->right = create(20);
  root->left->left=create(1);
  root->left->right=create(9);
  root->right->left=create(15);
  root->right->right=create(27);

  cout<<(is_valid_bst(root,INT_MIN,INT_MAX)?"Yes\n":"No\n");


  struct node * root1;
  root1 = create(10);

  root1->left = create(4);
  root1->right = create(20);
  root1->left->left=create(1);
  root1->left->right=create(9);
  root1->right->left=create(8);
  root1->right->right=create(27);

  cout<<(is_valid_bst(root1,INT_MIN,INT_MAX)?"Yes\n":"No\n");
  return 0;
}
