//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

int main() {

  //By Defualt It implements MaxHeap
  priority_queue<int> pq;

  //MinHeap
  priority_queue<int, vector<int>, greater<int> >pq1;

  for(int i=0;i<5;i++) {
    int no;
    cin>>no;

    pq.push(no);  //O(LogN)
    pq1.push(no);
  }

  
  while (!pq.empty()) {
    cout<<pq.top()<<" "; //O(1)
    pq.pop(); //O(LogN)
  }

  cout<<endl;

  while(!pq1.empty()) {
    cout<<pq1.top()<<" ";
    pq1.pop();
  }






  return 0;
}
