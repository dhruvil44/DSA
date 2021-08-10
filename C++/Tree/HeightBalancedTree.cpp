//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

//Check if a tree is height balanced tree or not.

//A tree is height balanced if the absolte difference between the left height and right height
//is less than or equal to 1 and all the nodes should follow the same rule.

/*

        1
       / \
      2   3
     / \
    4  5
    -> This is a height balanced tree because every node follows the rule.


        1
       / \
      2   3
     / \
    4  5
        \
         6
        /
       7
    ->This is not a height balanced tree because for node 2 the left height = 1 and right height = 3
      and the difference = 2 which violates the rule.
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


class Pair{
public:
  int height;
  bool balanced;
};

Pair is_height_balanced(node* root) {

  Pair p;
  if(!root) {
    p.height=0;
    p.balanced = true;
    return p;
  }

  Pair left = is_height_balanced(root->left);
  Pair right = is_height_balanced(root->right);

  p.height = max(left.height , right.height) + 1;

  //if the left-right<=1 and the left subtree and right subtree should be balanced
  if(abs(left.height - right.height)<=1 and left.balanced==true and right.balanced==true) {
    p.balanced = true;
  }
  else{
    p.balanced = false;
  }

  return p;
}

int main() {
  struct node * root;
  root = create(1);

  root->left = create(2);
  root->right = create(3);
  root->left->left=create(4);
  root->left->right=create(5);

  cout<<is_height_balanced(root).balanced<<endl;

  struct node * root1;
  root1 = create(1);

  root1->left = create(2);
  root1->right = create(3);
  root1->left->left=create(4);
  root1->left->right=create(5);
  root1->left->right->right=create(6);
  root1->left->right->right->left=create(7);

  cout<<is_height_balanced(root1).balanced<<endl;

  return 0;
}
