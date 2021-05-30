//Author: Dhruvil Patel
#include<bits/stdc++.h>
using namespace std;

class Queue{
private:
  stack<int> s1;
  stack<int> s2;

public:
  void push(int data) {
    s1.push(data);
  }

  bool empty() {
    return s1.empty();
  }

  bool size() {
    return s1.size();
  }

  void pop() {

    if(empty()) {
      return;
    }

    //transfer n-1 elements from s1 to s2
    while(s1.size()>1) {
      s2.push(s1.top());
      s1.pop();
    }

    //remove the last element from s1
    s1.pop();

    //transfer back from s2 to s1
    while(!s2.empty()) {
      s1.push(s2.top());
      s2.pop();
    }
  }


  int front() {
    //transfer n-1 elements from s1 to s2
    while(s1.size()>1) {
      s2.push(s1.top());
      s1.pop();
    }

    //get the last element from s1
    int element = s1.top();

    //tranfer back the elements from s2 to s1
    while(!s2.empty()) {
      s1.push(s2.top());
      s2.pop();
    }

    //return the element
    return element;
  }

};

int main() {

  Queue q;

  for(int i=1;i<10;i++) {
    q.push(i);
  }

  while(!q.empty()) {
    cout<<q.front()<<" ";
    q.pop();
  }


  return 0;
}
