/*Author : Dhruvil Patel(DP)*/

#include<bits/stdc++.h>

using namespace std;

struct node {

int data;
struct node *left;
struct node *right;

};

struct node *create(int x)
{

  struct node *newnode = new node;
  newnode->data=x;
  newnode->left=NULL;
  newnode->right=NULL;
  return newnode;
}



void levelorder(struct node *root)
{

if(root==NULL)
{
  return;
}
queue<struct node*>q;
q.push(root);

while(!q.empty())
{

  struct node *current = q.front();
  cout<<current->data<<" ";

  if(current->left)
  {
    q.push(current->left);
  }
  if(current->right)
  {
    q.push(current->right);
  }

  q.pop();

}


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

levelorder(root);


}
