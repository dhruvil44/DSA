//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

class Heap{

private:
  vector<int> v;
  bool minHeap;

  bool compare(int child, int parent, bool minHeap) {
    if(type==true) {
      return child<parent;
    }

    else{
      return child>parent;
    }
  }

public:
  Heap(int initialSize, bool minHeap=true) {
    v.reserve(initialSize);
    v.push_back(-1);
    this->type = type;
  }


  void push(int data) {
    v.push_back(data);

    int idx = v.size()-1;
    int parent = idx/2;

    while(idx>1 and compare(v[idx],v[parent],type)) {
      swap(v[idx],v[parent]);
      idx=parent;
      parent=parent/2;
    }
  }


  int top() {
    return v[1];
  }

  void heapify(int idx) {
    int idxToSwap = idx;
    int size = v.size();

    int left_idx = idx*2;
    int right_idx = left_idx+1;

    if(left_idx<size) {
      if(type==true) {
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
      if(type==true) {
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

    if(idxToSwap!=idx) {
      swap(v[idx],v[idxToSwap]);
      heapify(idxToSwap);
    }
  }

  void pop() {
    swap(v[1],v[v.size()-1]);
    v.pop_back();

    heapify(1);
  }

  bool empty() {
    return v.size()==1;
  }

};


int main() {

  Heap h(10,false);

  h.push(4);
  h.push(5);
  h.push(43);
  h.push(5);
  h.push(0);
  h.push(7);
  h.push(4);
  h.push(5);

  while(!h.empty()) {
    cout<<h.top()<<" ";
    h.pop();
  }


  return 0;
}
