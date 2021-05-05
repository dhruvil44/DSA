//Author:Dhruvil Patel(DP)

#include<bits/stdc++.h>

using namespace std;

#define MOD 1000000007;

int main()
{
  long long int n;
  cin>>n;

  int h[n];
  int i;
  for(i=0;i<n;i++)
  {
    cin>>h[i];
  }

  long int dp[n];
  dp[0]=0;
  dp[1]=abs(h[1]-h[0]);

  for(i=2;i<n;i++)
  {
    dp[i]=min(dp[i-2]+abs(h[i]-h[i-2]),dp[i-1]+abs(h[i]-h[i-1]));
  }
  cout<<dp[n-1]<<endl;
  return 0;
}
