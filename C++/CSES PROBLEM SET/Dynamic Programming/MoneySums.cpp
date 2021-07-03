//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

/*
https://cses.fi/problemset/task/1745
*/

int main() {

  int n;
  cin>>n;

  int coins[n];
  int sum=0;
  for(int i=0;i<n;i++) {
    cin>>coins[i];
    sum+=coins[i];
  }

  bool dp[n+1][sum+1];

  //Init first row with false
  for(int i=0;i<=sum;i++) {
    dp[0][i]=false;
  }

  //Init first col with true
  for(int i=0;i<=n;i++) {
    dp[i][0]=true;
  }


  for(int i=1;i<=n;i++) {
    for(int j=1;j<=sum;j++) {
      if(j>=coins[i-1]) {
        dp[i][j] = (dp[i-1][j] || dp[i-1][j-coins[i-1]]);
      }
      else{
        dp[i][j] = dp[i-1][j];
      }
    }
  }

  int ans=0;
  for(int i=1;i<=sum;i++) {
    if(dp[n][i]==true) {
      ans++;
    }
  }

  cout<<ans<<endl;
  for(int i=1;i<=sum;i++) {
    if(dp[n][i]==true) {
      cout<<i<<" ";
    }
  }

  return 0;
}
