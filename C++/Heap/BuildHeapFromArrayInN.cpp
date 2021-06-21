//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;


void heapify(int idx, vector<int> &v, bool isMinHeap) {
  int idxToSwap = idx;
  int size = v.size();

  int left_idx = 2*idx;
  int right_idx = left_idx+1;

  if(left_idx<size) {
    if(isMinHeap) {
      if(v[left_idx]<v[idx]) {
        idxToSwap = left_idx;
      }
    }
    else{
      if(v[left_idx]>v[idx]) {
        idxToSwap = left_idx;
      }
    }
  }

  if(right_idx<size) {
    if(isMinHeap) {
      if(v[right_idx]<v[idxToSwap]) {
        idxToSwap = right_idx;
      }
    }
    else{
      if(v[right_idx]>v[idxToSwap]) {
        idxToSwap = right_idx;
      }
    }
  }

  if(idx!=idxToSwap) {
    swap(v[idx],v[idxToSwap]);
    heapify(idxToSwap,v,isMinHeap);
  }
}

//O(N) time complexity to build a heap from an array.
//Here instead of iterating all the elements of the array from the beginning,
//We iterate from the n/2th element because after n/2th node all are leaf nodes,
//so we dont require to heapify them and we call heapify on other nodes.
//so here we are building heap from bottom to top.
void buildHeapOptimised(vector<int> &v, bool isMinHeap) {
  for(int i=(v.size()-1)/2;i>=1;i--) {
    heapify(i,v,isMinHeap);
  }
}


void print(vector<int> v) {

  for(auto x: v){
    cout<<x<<" ";
  }

  cout<<endl;
}

int main() {

  vector<int> v = {-1,33,2,1,4,5,6,0,90};
  print(v);

  //building minHeap
  cout<<"MinHeap---> ";
  buildHeapOptimised(v,true);
  print(v);

  cout<<"MaxHeap---> ";
  //building maxheap
  buildHeapOptimised(v,false);
  print(v);


  return 0;
}
