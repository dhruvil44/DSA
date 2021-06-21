//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

bool compare(int child, int parent, bool type) {
  //if minheap = true
  if(type==true) {
    return child<parent;
  }

  //else maxheap
  else{
    return child>parent;
  }
}

//By Default make MinHeap
void buildHeap(vector<int> &v, bool type=true) {

  for(int i=2;i<v.size();i++) {
    int idx = i;
    int parent = idx/2;

    while(idx>1 and compare(v[idx],v[parent],type)) {
      swap(v[idx],v[parent]);
      idx=parent;
      parent=parent/2;
    }
  }
}

void print(vector<int> v) {
  for(auto x: v) {
    cout<<x<<" ";
  }

  cout<<endl;
}

int main() {

  vector<int> v = {-1,33,2,1,4,5,6,0,90};
  print(v);

  //building minHeap
  cout<<"MinHeap---> ";
  buildHeap(v);
  print(v);

  cout<<"MaxHeap---> ";
  //building maxheap
  buildHeap(v,false);
  print(v);

  return 0;
}
