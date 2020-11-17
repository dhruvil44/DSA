//Author:Dhruvil Patel(DP)

#include<bits/stdc++.h>

using namespace std;

//https://www.geeksforgeeks.org/count-subsequences-product-less-k/

int numOfSubSeq(int a[], int n, int k)
{
  int dp[k+1][n+1];

  for(int i=0;i<=n;i++)
  {
    dp[0][i]=0;
  }

  for(int i=0;i<=k;i++)
  {
    dp[i][0]=0;
  }

  for(int i=1;i<=k;i++)
  {
    for(int j=1;j<=n;j++)
    {
      dp[i][j]=dp[i][j-1];

      if(i>=a[j-1] && a[j-1]!=0)
      {
        dp[i][j]+=dp[i/a[j-1]][j-1]+1;
      }
    }
  }

  // for(int i=0;i<=k;i++)
  // {
  //   for(int j=0;j<=n;j++)
  //   {
  //     cout<<dp[i][j]<<" ";
  //   }
  //
  //   cout<<endl;
  // }

  return dp[k][n];
}

int main()
{
int a[]={4,8,7,2};
int k=50;

cout<<numOfSubSeq(a,4,k);

  return 0;
}
