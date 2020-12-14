//Author: Dhruvil Patel

#include<bits/stdc++.h>

using namespace std;

int getValue(char c)
{
  if(c=='(' || c==')')
  {
    return 100;
  }

  if(c=='^')
  {
    return 99;
  }

  if(c=='*' || c=='/')
  {
    return 98;
  }

  return 97;
}

bool isOneHigherThanOther(char one, char two)
{
  int p1=getValue(one);
  int p2=getValue(two);

  if(p1>p2)
  {
    return true;
  }

  return false;
}



bool isOperator(char c)
{
  if(c=='(' || c==')' || c=='*' ||c=='/' || c=='+' || c=='-' || c=='^')
  {
    return true;
  }

  return false;
}



void convertInfixToPostfix(string infix)
{

  stack<char> st;

  for(int i=0;i<infix.size();i++){

    if(isOperator(infix[i]))
    {

      if(st.empty() || (isOneHigherThanOther(infix[i],st.top()) && infix[i]!=')') || infix[i]=='(' || st.top()=='(')
      {
        st.push(infix[i]);
      }


      else if(infix[i]==')')
      {
        while(1)
        {
          if(st.top()=='(')
          {
            st.pop();
            break;
          }
          cout<<st.top();
          st.pop();
        }

      }


      else{
        while( !st.empty() && (getValue(st.top())==getValue(infix[i]) || getValue(st.top())>getValue(infix[i])))
        {
          if(infix[i]=='^' && st.top()=='^')
          {
              break;
          }

          else{
            cout<<st.top();
            st.pop();
          }


        }

        st.push(infix[i]);
      }

    }



    else{
      cout<<infix[i];
    }

  }

  while(!st.empty())
  {
    cout<<st.top();
    st.pop();
  }

}

int main()
{

  string infix="k+l-m*n+(o^p)*w/u/v*t+q";

  convertInfixToPostfix(infix);

  return 0;
}
