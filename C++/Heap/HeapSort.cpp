//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;



//Buiding Max Heap
void heapify(int idx, vector<int> &v, int n) {
  int idxToSwap = idx;
  int size = n;

  int left_idx = 2*idx;
  int right_idx = left_idx+1;

  if(left_idx<size) {
      if(v[left_idx]>v[idx]) {
        idxToSwap = left_idx;
      }
  }

  if(right_idx<size) {
      if(v[right_idx]>v[idxToSwap]) {
        idxToSwap = right_idx;
      }
  }

  if(idx!=idxToSwap) {
    swap(v[idx],v[idxToSwap]);
    heapify(idxToSwap,v,n);
  }
}

//Building Max Heap
void buildHeapOptimised(vector<int> &v) {
  for(int i=(v.size()-1)/2;i>=1;i--) {
    heapify(i,v,v.size());
  }
}


void heapSort(vector<int> &v) {
  //Building Max Heap from the array
  buildHeapOptimised(v);
  int n = v.size();

  //Loop until the size of the sorted array(heap) is greater than 1
  while(n>1) {
    //swap the first and last element
    swap(v[1],v[n-1]);

    //Reduce the size of the heap by 1
    n--;

    //Call heapify on the first n elements
    heapify(1,v,n);
  }

}


void print(vector<int> v) {
  for(auto x: v) {
    cout<<x<<" ";
  }

  cout<<endl;
}

int main() {

  vector<int> v;
  v.push_back(-1);

  int n;
  cin>>n;

  for(int i=0;i<n;i++) {
    int temp;
    cin>>temp;
    v.push_back(temp);
  }

  print(v);

  heapSort(v);
  print(v);


  return 0;
}
