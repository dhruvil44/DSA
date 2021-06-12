//Author: Dhruvil Patel

#include<bits/stdc++.h>

using namespace std;

//Sort the stack using only recursion

void insertXAtPlace(stack<int> &st, int x) {
  if(st.empty()) {
    st.push(x);
    return;
  }

  if(x<=st.top()) {
    st.push(x);
    return;
  }

  int data = st.top();
  st.pop();
  insertXAtPlace(st,x);
  st.push(data);
}

void sortStack(stack<int>& st)
{
  if(st.empty()) {
    return;
  }

  int x = st.top();
  st.pop();

  sortStack(st);
  insertXAtPlace(st,x);
}

int main()
{

  stack<int> st;

  st.push(4);
  st.push(9);
  st.push(8);
  st.push(10);

  sortStack(st);

  while(!st.empty())
  {
    cout<<st.top()<<endl;
    st.pop();
  }

}
