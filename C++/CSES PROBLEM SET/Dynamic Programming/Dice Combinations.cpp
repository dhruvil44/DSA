//Author: Dhruvil Patel(DP)

#include<bits/stdc++.h>

using namespace std;

int main()
{

  long long int n;
  cin>>n;

  vector<long long int>dp(n+1);
  dp[0]=0;
  dp[1]=1;

  for(long long int i=2;i<=n;i++)
  {
    for(int j=1;j<=6;j++)
    {
      if(i-j>=0)
        dp[i]+=1+dp[i-j];

      else{
        break;
      }
    }
  }

  cout<<dp[n]<<endl;

  return 0;
}
