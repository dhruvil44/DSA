//Author: Dhruvil Patel

#include<bits/stdc++.h>

using namespace std;

int LCS(string s1,string s2)
{

  int dp[s1.size()+1][s2.size()+1];

  int n1=s1.size();
  int n2=s2.size();

  int i,j;

  int longestLength=INT_MIN;

  for(i=0;i<=n1;i++)
  {
    for(j=0;j<=n2;j++)
    {
      if(i==0 || j==0)
      {
        dp[i][j]=0;
      }

      else{
        if(s1[i-1]==s2[j-1])
        {
          dp[i][j]=1+dp[i-1][j-1];
        }
        else{
          dp[i][j]=0;
        }
      }


      longestLength=max(longestLength,dp[i][j]);

    }
  }

  return longestLength;
}

int main()
{

  string s1="abcdxyz";
  string s2="xyzabcde";

  cout<<LCS(s1,s2);

  return 0;
}
