//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

class node{
public:
  int data;
  node* left;
  node* right;

  node(int data) {
    this->data = data;
  }
};


void bfs(node* root) {
  if(!root) {
    return;
  }

  queue<node*> q;
  q.push(root);
  q.push(NULL);
  while(!q.empty()) {

    node* n = q.front();
    q.pop();

    if(n==NULL) {
      cout<<"\n";
      if(!q.empty()) {
        q.push(NULL);
        continue;
      }
      else{
        break;
      }
    }

    cout<<n->data<<" ";
    if(n->left) {
      q.push(n->left);
    }

    if(n->right) {
      q.push(n->right);
    }

  }
}

node* buildTreeFromTraversal(int preorder[], int inorder[], int start, int end) {

  static int i = 0;

  if(start>end) {
    return NULL;
  }

  node* root = new node(preorder[i]);

  //find the node in the inorder
  int idx=-1;
  for(int j=start;j<=end;j++) {
    if(inorder[j]==preorder[i]) {
      idx=j;
      break;
    }
  }

  i++;
  root->left = buildTreeFromTraversal(preorder,inorder,start,idx-1);
  root->right = buildTreeFromTraversal(preorder,inorder,idx+1,end);

  return root;

}

int main() {

  int preorder[] = {1,2,3,4,8,5,6,7};
  int inorder[] = {3,2,8,4,1,6,7,5};
  int n = sizeof(preorder)/sizeof(int);

  node* root = buildTreeFromTraversal(preorder,inorder,0,n-1);
  bfs(root);

  return 0;
}
