//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

//Given an array.
//Make a height balanced binary tree out of i.

class node{
public:
  int data;
  node* left;
  node* right;

  node(int data) {
    this->data = data;
  }
};

node* buildBalancedTree(int a[], int start, int end) {
  if(start>end) {
    return NULL;
  }

  int mid = (start+end)/2;

  node* n = new node(a[mid]);
  n->left = buildBalancedTree(a,start,mid-1);
  n->right = buildBalancedTree(a,mid+1,end);

  return n;
}

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

int main() {

  int a[] = {1,2,3,4,5,6,7};
  int n = 7;

  node* root = buildBalancedTree(a,0,n-1);
  bfs(root);

  return 0;
}
