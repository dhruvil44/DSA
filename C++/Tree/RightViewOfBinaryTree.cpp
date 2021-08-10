//Author: Dhruvil Patel

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


void rightView(node* root, int curr_level, int &maxLevel) {
  if(!root) {
    return;
  }

  if(curr_level>maxLevel) {
    cout<<root->data<<" ";
    maxLevel = curr_level;
  }

  rightView(root->right,curr_level+1,maxLevel);
  rightView(root->left,curr_level+1,maxLevel);
}

int main() {

  struct node * root;
  root = create(10);

  root->left = create(5);
  root->right = create(4);
  root->left->left=create(8);
  root->left->right=create(9);
  root->left->right->left=create(14);
  root->left->right->left->right=create(20);
  root->right->left = create(2);
  root->right->right = create(6);
  root->right->left->left = create(7);
  root->right->left->right = create(3);

  /*

          10
         /  \
        5     4
       / \   / \
      8   9  2  6
         /  / \
        14 7   3
         \
         20

         rightView = 10 4 6 3 20
  */

  int maxLevel = -1;
  rightView(root,0,maxLevel);

  return 0;
}
