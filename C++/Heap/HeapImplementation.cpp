//Author: Dhruvil Patel

#include<bits/stdc++.h>

using namespace std;


class Heap {

private:
  vector<int> heap;
  bool isMinHeap=true;

public:

  //initializing the Heap
  Heap(bool isMinHeap) {
    heap.push_back(-1);
    this->isMinHeap=isMinHeap;
  }

  bool compare(int a, int b) {
    if(this->isMinHeap) {
      return a<b;
    }

    return a>b;
  }


  void insert(int data) {
    heap.push_back(data);
    this->heapifyInsert();
    cout<<"Top of the heap is "<<heap[1]<<endl;
  }

  void heapifyInsert() {

    int child=heap.size()-1;
    int parent=child/2;

    while(compare(heap[child],heap[parent]) && child!=1) {
      swap(heap[child],heap[parent]);
      child=parent;
      parent=child/2;
    }
  }

  //either delete the first element or the last element
  void deleteData(int data) {
    if(data!=heap[1] && data!=heap[heap.size()-1]) {
      cout<<"Enter valid data";
      return;
    }

    if(heap[1]==data) {
      swap(heap[1],heap[heap.size()-1]);
    }
    heap.pop_back();
    this->heapifyDelete();
  }

  void heapifyDelete() {
    int parent=1;
    int childOne=parent*2;
    int childTwo=childOne+1;

    if(childTwo>=heap.size()) {
      childTwo=childOne;
    }

    while(childOne<heap.size() && compare(min(heap[childOne],heap[childTwo]),heap[parent])) {
      int indexToSwapWith=heap[childOne]<heap[childTwo]?childOne:childTwo;
      swap(heap[parent],heap[indexToSwapWith]);
      parent=indexToSwapWith;
      childOne=parent*2;
      childTwo=childOne+1;
    }
  }


  void printHeap() {
    for(auto x: heap) {
      cout<<x<<" ";
    }
    cout<<endl;
  }


};


int main() {

  Heap heap(false);
  heap.insert(100);
  heap.insert(25);
  heap.insert(1);
  heap.insert(2);
  heap.insert(7);
  heap.insert(36);
  heap.insert(3);
  heap.insert(17);
  heap.insert(19);
  heap.insert(0);
  cout<<"Printing heap\n";
  heap.printHeap();

  heap.deleteData(0);
  cout<<"Printing Heap\n";
  heap.printHeap();

  heap.deleteData(1);
  cout<<"Printing Heap\n";
  heap.printHeap();

  Heap heap2(true);
  heap2.insert(4);
  heap2.insert(9);
  heap2.insert(6);
  cout<<"Printing 2nd Heap\n";
  heap2.printHeap();

  heap2.deleteData(4);
  cout<<"Printing 2nd Heap\n";
  heap2.printHeap();

  heap2.deleteData(6);
  cout<<"Printing 2nd Heap\n";
  heap2.printHeap();

  heap2.deleteData(9);
  cout<<"Printing 2nd Heap\n";
  heap2.printHeap();




  return 0;
}
