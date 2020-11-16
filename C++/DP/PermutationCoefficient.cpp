//Author:Dhruvil Patel(DP)

#include<bits/stdc++.h>

using namespace std;

int nPk(int n, int k)
{
  int dp[n+1][k+1];

  for(int i=0;i<=n;i++)
  {
    dp[i][0]=1;
  }

  for(int i=1;i<=k;i++)
  {
    dp[0][i]=0;
  }

  for(int i=1;i<=n;i++)
  {
    for(int j=0;j<=k;j++)
    {
      dp[i][j]=dp[i-1][j] + j*dp[i-1][j-1];
    }
  }


  return dp[n][k];
}


int main()
{

  int n=10;
  int k=3;
  cout<<nPk(n,k);

  return 0;
}
