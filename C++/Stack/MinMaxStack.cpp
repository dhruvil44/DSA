//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

//Design the stack class that supports the following operations
//1)Push() 2) Pop()
//3)GetMin() (In O(1) time)
//4)GetMax() (In O(1) time)

class Stack {
  private:
    stack<int> s;
    stack<int> minStack;
    stack<int> maxStack;

  public:
    void push(int data) {
      if(s.empty()) {
        minStack.push(data);
        maxStack.push(data);
      }

      else{
          if(data<=minStack.top()) {
            minStack.push(data);
          } else{
            minStack.push(minStack.top());
          }

          if(data>=maxStack.top()) {
            maxStack.push(data);
          } else{
            maxStack.push(maxStack.top());
          }
      }


      s.push(data);

    }

    int top() {
      return s.top();
    }

    void pop() {
      s.pop();
      minStack.pop();
      maxStack.pop();
    }

    int getMin() {
      return minStack.top();
    }

    int getMax() {
      return maxStack.top();
    }

    bool empty() {
      return s.empty();
    }


};

int main() {


  Stack s;

  s.push(3);
  s.push(4);
  s.push(2);
  s.push(0);
  s.push(5);

  while(!s.empty()) {
    cout<<s.top()<<" ";
    cout<<s.getMax()<<" ";
    cout<<s.getMin()<<" ";
    cout<<endl;
    s.pop();

  }


  return 0;
}
