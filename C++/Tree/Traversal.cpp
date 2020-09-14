//Author:Dhruvil Patel(DP)

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

void inorder(struct node *root)
{
  struct node *temp = root;
  if(temp==NULL)
  {
    return;
  }
  inorder(root->left);
  cout<<temp->data<<" ";
  inorder(root->right);
}
void preorder(struct node *root)
{
  struct node *temp = root;
  if(temp==NULL)
  {
    return;
  }
  cout<<temp->data<<" ";
  preorder(root->left);
  preorder(root->right) ;
}

void postorder(struct node *root)
{
  struct node *temp = root;
  if(temp==NULL)
  {
    return;
  }
  postorder(root->left);
  postorder(root->right);
  cout<<temp->data<<" ";

}






int main()
{

struct node *root;

root=create(4);
root->left = create(3);
root->right = create(2);
root->left->left = create(15);
root->left->left->right = create(20);

inorder(root);
cout<<endl;

preorder(root);
cout<<endl;

postorder(root);
cout<<endl;




  return 0;
}
