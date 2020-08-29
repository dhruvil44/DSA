/*Author : Dhruvil Patel*/

#include<bits/stdc++.h>

using namespace std;

struct node{

int data;
struct node *left;
struct node *right;

};


struct node * create(int x)
{

struct node *newnode = (struct node *)malloc(sizeof(struct node));
newnode->data = x;
newnode->left=NULL;
newnode->right=NULL;

return newnode;
}

struct node *lca(struct node *root,int x, int y)
{

  if(root==NULL)
  {
    return NULL;
  }

  if(root->data==x || root->data==y)
  {
    return root;
  }



  struct node *left=lca(root->left,x,y);
  struct node *right=lca(root->right,x,y);

  if(left && right)
  {
    return root;
  }

  if(left)
  {
    return left;
  }

  else{
    return right;
    }






}






int main()
{
struct node *root=create(1);
root->left=create(2);
root->right=create(3);
root->right->right=create(6);
root->right->left=create(4);
root->right->left->right=create(5);


struct node *t = lca(root,6,1);
cout<<t->data;

  return 0;
}
