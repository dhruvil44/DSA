//Author:Dhruvil Patel(DP)

#include <bits/stdc++.h>

using namespace std;

int editDistance(string s1, string s2)
{
  int dp[s1.size()][s2.size()];

  int f=0;
  int temp=0;
  for(int i=0;i<s2.size();i++)
  {
    if(s1[0]==s2[i] && f==0)
    {
      dp[0][i]=temp;
      f=1;
    }
    else{
      dp[0][i]=++temp;
    }
  }


  f=0;
  temp=0;
  for(int i=0;i<s1.size();i++)
  {
    if(s2[0]==s1[i] && f==0)
    {
      dp[i][0]=temp;
      f=1;
    }

    else{
      dp[i][0]=++temp;
    }
  }


  for(int i=1;i<s1.size();i++)
  {
    for(int j=1;j<s2.size();j++)
    {
      if(s1[i]==s2[j])
      {
        dp[i][j]=dp[i-1][j-1];
      }

      else{
        dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
      }
    }
  }
  return dp[s1.size()-1][s2.size()-1];
}

int main() {

  //converting s1 to s2
  string s1="saturday";
  string s2="sunday";

  cout<<editDistance(s1,s2);

  return 0;
}
