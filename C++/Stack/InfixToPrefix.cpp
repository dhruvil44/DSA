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


void convertInfixToPrefix(string tempInfix)
{

  string infix="";
  for(int i=tempInfix.size()-1;i>=0;i--)
  {
    infix+=tempInfix[i];
  }

  string ans="";

  stack<char> st;


  for(int i=0;i<infix.size();i++)
  {
    if(isOperator(infix[i]))
    {
          if(st.empty() || (isOneHigherThanOther(infix[i],st.top()) && infix[i]!='(') || infix[i]==')' || st.top()==')')
          {
            st.push(infix[i]);
          }

          else if(infix[i]=='(')
          {
            while(1)
            {
              if(st.top()==')')
              {
                st.pop();
                break;
              }

              ans+=st.top();
              st.pop();
            }
          }


          else{
            while(!st.empty() && (getValue(infix[i])==getValue(st.top())) || getValue(st.top())>getValue(infix[i]))
            {
                if(getValue(infix[i])==getValue(st.top()) && st.top()!='^')
                {
                  break;
                }

                else{
                  ans+=st.top();
                  st.pop();
                }
            }

            st.push(infix[i]);

          }

    }



    else{
      ans+=infix[i];
    }



  }

  while(!st.empty())
  {
    cout<<st.top();
    st.pop();
  }

  reverse(ans.begin(),ans.end());
  cout<<ans;

}

int main()
{

  string infix="k+l-m*n+(o^p)*w/u/v*t+q";

  convertInfixToPrefix(infix);

  cout<<endl;

  convertInfixToPrefix("a+b*c-d");

  return 0;
}
