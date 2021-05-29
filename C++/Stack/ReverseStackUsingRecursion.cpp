//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

//Reverse the Stack using only Recursion

void transferAtBottom(stack<int> &s, int x) {

  //Base Case
  if(s.empty()) {
    s.push(x);
    return;
  }

  int data = s.top();
  s.pop();
  transferAtBottom(s,x);
  s.push(data);

}


void reverseStack(stack<int> &s) {

  //Base Case
  if(s.empty()) {
    return;
  }

  int x = s.top();
  s.pop();
  reverseStack(s);
  transferAtBottom(s,x);

}


int main() {

  stack<int> s;

  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);

  reverseStack(s);

  while(!s.empty()) {
    cout<<s.top()<<endl;
    s.pop();
  }
  return 0;
}
