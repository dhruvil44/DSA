//Author: Dhruvil Patel

#include<bits/stdc++.h>

using namespace std;


int solvePostfix(string postfix)
{

  stack<int> st;

  for(int i=0;i<postfix.size();i++)
  {
    if(postfix[i]=='+')
    {
      int t1 = st.top();
      st.pop();

      int t2 = st.top();
      st.pop();

      st.push(t1+t2);
      continue;
    }



      if(postfix[i]=='-')
      {
        int t1 = st.top();
        st.pop();

        int t2 = st.top();
        st.pop();

        st.push(t2-t1);
        continue;
      }



        if(postfix[i]=='*')
        {
          int t1 = st.top();
          st.pop();

          int t2 = st.top();
          st.pop();

          st.push(t1*t2);
          continue;
        }



          if(postfix[i]=='/')
          {
            int t1 = st.top();
            st.pop();

            int t2 = st.top();
            st.pop();

            st.push(t2/t1);
            continue;
          }

          st.push(postfix[i]-'0');
  }


  return st.top();
}

int main()
{
  //2+3*4+5
  string postfix="234*+5+";

  cout<<solvePostfix(postfix);

  return 0;
}
