//Author: Dhruvil Patel

#include<bits/stdc++.h>

using namespace std;

void sort(stack<int> st)
{
  if(st.size()<=1)
  {
    return;
  }

  int t1 = st.top();
  st.pop();

  int t2 = st.top();
  st.pop();
}

int main()
{

  stack<int> st;

  sort(st);

  while(!st.empty())
  {
    cout<<st.top();
    st.pop();
  }

}
