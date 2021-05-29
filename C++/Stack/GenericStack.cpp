//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Stack {
  private:
    vector<T> v;

  public:

    void push(T data) {
      v.push_back(data);
    }


    bool empty() {
      return v.size()==0;
    }

    void pop() {
      if(!empty()) {
        v.pop_back();
      }
    }


    T top() {
      return v[v.size()-1];
    }

};

int main() {

  Stack<int> st;

  for(int i=0;i<=4;i++) {
    st.push(i*i);
  }


  while(!st.empty()) {
    cout<<st.top()<<endl;
    st.pop();
  }

  return 0;
}
