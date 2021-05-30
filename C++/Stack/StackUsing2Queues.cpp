//Author: Dhruvil Patel
#include<bits/stdc++.h>
using namespace std;

class Stack{
private:
  queue<int> q1;
  queue<int> q2;

public:
  void push(int data) {
    q1.push(data);
  }

  bool empty() {
    return q1.size()==0;
  }

  void pop() {

    if(empty()) {
      return;
    }
    //transfer n-1 elements from q1 to q2
    while(q1.size()!=1) {
      q2.push(q1.front());
      q1.pop();
    }

    //remove the last element from q1
    q1.pop();

    //transfer back from q2 to q1
    while(!q2.empty()) {
      q1.push(q2.front());
      q2.pop();
    }
  }

  int top() {
    //transfer n-1 elements from q1 to q2
    while(q1.size()!=1) {
      q2.push(q1.front());
      q1.pop();
    }
    //get the last element
    int element = q1.front();
    q2.push(element);
    q1.pop();

    //transfer back from q2 to q1
    while(!q2.empty()) {
      q1.push(q2.front());
      q2.pop();
    }

    //return the element
    return element;
  }

  int size() {
    return q1.size();
  }
};


int main() {

  Stack s;

  for(int i=1;i<5;i++) {
    s.push(i);
  }

  while(!s.empty()) {
    cout<<s.top()<<endl;
    s.pop();
  }


  return 0;
}
