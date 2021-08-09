//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

void build(int start, int end, int a[], int seg_tree[], int idx) {

  if(start==end) {
    seg_tree[idx] = a[start];
    return;
  }

  int mid = (start+end)/2;
  build(start,mid,a,seg_tree,2*idx+1);
  build(mid+1,end,a,seg_tree,2*idx+2);

  seg_tree[idx] = seg_tree[2*idx+1] + seg_tree[2*idx+2];
}


int get_sum_in_a_range(int l, int r, int start, int end, int seg_tree[], int idx) {

  //if the current node range lies completely in the given query range
  if(start>=l and r>=end) {
    return seg_tree[idx];
  }

  //if there is no overlapping
  if(end<l || start>r) {
    return 0;
  }

  int mid = (start+end)/2;
  int left = get_sum_in_a_range(l,r,start,mid,seg_tree,2*idx+1);
  int right = get_sum_in_a_range(l,r,mid+1,end,seg_tree,2*idx+2);

  return (left+right);
}

int main() {

  int a[] = {4,5,9,8,2,6,7,0,4,10};
  int start = 0;
  int end = 9;
  int seg_tree[10*4];
  int idx = 0;
  build(start,end,a,seg_tree,idx);

  int queries = 5;
  while(queries--) {
    int l,r;
    cin>>l>>r;
    idx=0;
    cout<<get_sum_in_a_range(l,r,start,end,seg_tree,idx);
  }

  return 0;
}
