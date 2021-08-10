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

void print_at_level_k(node* root, int k) {
  if(root==NULL) {
    return;
  }

  if(k==0) {
    cout<<root->data<<" ";
    return;
  }

  print_at_level_k(root->left,k-1);
  print_at_level_k(root->right,k-1);
}


int print_nodes_at_distance_k(node* root, node* target, int k) {

  if(root==NULL) {
    return -1;
  }

  if(root==target) {
    print_at_level_k(root,k);
    return 0;
  }

  int left_dist = print_nodes_at_distance_k(root->left,target,k);

  //it means that we need to go to the right
  if(left_dist!=-1) {
      if(1+left_dist==k) {
        cout<<root->data<<" ";
      }
      else{
        print_at_level_k(root->right,k-left_dist-2);
      }

      return left_dist+1;
  }

  int right_dist = print_nodes_at_distance_k(root->right,target,k);

  if(right_dist!=-1) {
    if(1+right_dist==k) {
      cout<<root->data<<" ";
    }
    else{
      print_at_level_k(root->left,k-right_dist-2);
    }
    return right_dist+1;
  }

  return -1;
}


int main() {

  struct node* root = create(1);
  root->left = create(2);
  root->right = create(3);
  root->left->left = create(4);
  root->left->right = create(5);
  root->left->left->left = create(6);
  root->left->left->right = create(7);
  root->left->right->right = create(8);

  /*

            1
           / \
          2   3
         / \
        4   5
       / \   \
      6   7   8

      target = 4,k=3
      output = 8,3

      target = 4, k=2
      output = 5,1

      target = 6, k=3
      output = 5,1

  */

  int x = print_nodes_at_distance_k(root,root->left->left,3);
  return 0;
}
