//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

//Reverse the stack using only single extra stack

void transfer(stack<int> &src, stack<int> &dest, int number_of_elements_to_transfer) {

  while(number_of_elements_to_transfer--) {
    dest.push(src.top());
    src.pop();
  }

}

void reverseStack(stack<int> &s) {

  //take an extra stack
  stack<int> s1;

  int n = s.size();

  for(int i=0;i<n;i++) {

    int x = s.top();
    s.pop();

    //transfer from s to s1
    transfer(s,s1,n-i-1);

    //push the x in the stack
    s.push(x);

    //transfer from s1 to s
    transfer(s1,s,n-i-1);
  }

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
