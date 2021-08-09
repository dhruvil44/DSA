//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

void build(int start, int end, int idx, int a[], int seg_tree[]) {

  if(start==end) {
    seg_tree[idx] = a[start];
    return;
  }

  int mid = (start+end)/2;
  build(start,mid,2*idx+1,a,seg_tree);
  build(mid+1,end,2*idx+2,a,seg_tree);

  seg_tree[idx] = max(seg_tree[2*idx+1],seg_tree[2*idx+2]);
}


int get_max_in_range(int l, int r, int start, int end, int seg_tree[], int idx) {

  //if the current node range lies completely in the given query range
  if(l<=start and r>=end) {
    return seg_tree[idx];
  }

  //if it does not overlap
  if(end<l || start>r) {
    return INT_MIN;
  }

  int mid = (start+end)/2;

  int left_max = get_max_in_range(l,r,start,mid,seg_tree,2*idx+1);
  int right_max = get_max_in_range(l,r,mid+1,end,seg_tree,2*idx+2);

  return max(left_max,right_max);
}



int main() {

  int a[] = {4,5,9,8,2,6,7,0,4,10};
  int start=0;
  int end = 9;
  int idx=0;
  int seg_tree[10*4];
  build(start,end,idx,a,seg_tree);

  int queries = 5;
  while(queries--) {
    int l,r;
    cin>>l>>r;

    idx=0;
    cout<<get_max_in_range(l,r,start,end,seg_tree,idx);
  }

  return 0;
}
