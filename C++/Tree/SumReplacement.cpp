//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;


//Given a Binary Tree where each node has positive and negative values.
// Convert this to a tree where each node contains the sum of the left and right sub trees
// in the original tree.
// The values of leaf nodes remain as it is.

/*

Input:-
         8
        / \
       10 13
      / \   \
     4   3   -3

Output:-

         27
        / \
       7   -3
      / \   \
     4   3   -3
*/



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



void dfs(node* root) {
  if(!root) {
    return;
  }

  cout<<root->data<<" ";
  dfs(root->left);
  dfs(root->right);
}


int replace_by_sum_of_children(node* root) {
  if(!root) {
    return 0;
  }

  if(root->left==NULL and root->right==NULL) {
    return root->data;
  }

  int left_sum = replace_by_sum_of_children(root->left);
  int right_sum = replace_by_sum_of_children(root->right);

  int old_data = root->data;
  root->data = left_sum+right_sum;

  return old_data+left_sum+right_sum;
}

int main() {

  struct node * root;
  root = create(8);

  root->left = create(10);
  root->right = create(13);
  root->left->left=create(4);
  root->left->right=create(3);
  root->right->right=create(-3);

  dfs(root);
  cout<<endl;
  replace_by_sum_of_children(root);
  dfs(root);
  cout<<endl;
  return 0;
}
