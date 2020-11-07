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

  struct node * newNode = new struct node;
  newNode->data = x;
  newNode->left=NULL;
  newNode->right=NULL;

  return newNode;
}


void sum(node *root, int &s)
{
  if(!root)
  {
    return;
  }

  s+=root->data;
  sum(root->left,s);
  sum(root->right,s);
}

int findLargestSum(node *root)
{
  if(!root)
  {
    return 0;
  }

  int currSum=0;
  sum(root, currSum);

  return max(currSum,max(findLargestSum(root->left) , findLargestSum(root->right)));

}


int main()
{
     node* root = create(1);
     root->left = create(-2);
     root->right = create(3);
     root->left->left = create(4);
     root->left->right = create(5);
     root->right->left = create(-6);
     root->right->right = create(2);

     cout<<findLargestSum(root);

  return 0;
}
