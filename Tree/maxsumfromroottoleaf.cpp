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


int maxsumfromroottoleaf(struct node *root)
{

  if(root==NULL)
  {
    return 0;
  }


  int sumleft=maxsumfromroottoleaf(root->left);

  int sumright=maxsumfromroottoleaf(root->right);

  return(max(sumleft,sumright)+root->data);



}





int main()
{
struct node *root=create(1);
root->left=create(2);
root->right=create(3);
root->right->right=create(6);
root->right->left=create(4);
root->right->left->right=create(5);


vector<int>v;
cout<<maxsumfromroottoleaf(root);
cout<<endl;



  return 0;
}
