//Author: Dhruvil Patel

#include<bits/stdc++.h>


using namespace std;


int solvePrefix(string prefix)
{

  stack<int> st;

  for(int i=prefix.size()-1;i>=0;i--)
  {
    if(prefix[i]=='+')
    {
      int t1 = st.top();
      st.pop();

      int t2 = st.top();
      st.pop();

      st.push(t1+t2);
      continue;
    }



      if(prefix[i]=='-')
      {
        int t1 = st.top();
        st.pop();

        int t2 = st.top();
        st.pop();

        st.push(t2-t1);
        continue;
      }



        if(prefix[i]=='*')
        {
          int t1 = st.top();
          st.pop();

          int t2 = st.top();
          st.pop();

          st.push(t1*t2);
          continue;
        }



          if(prefix[i]=='/')
          {
            int t1 = st.top();
            st.pop();

            int t2 = st.top();
            st.pop();

            st.push(t2/t1);
            continue;
          }

          st.push(prefix[i]-'0');
  }


  return st.top();
}


int main()
{

  //infix = 2+3*4-5

  string prefix = "+-5*432";

  cout<<solvePrefix(prefix);

  return 0;
}
