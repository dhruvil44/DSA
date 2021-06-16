//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

/*
https://cses.fi/problemset/task/1635
*/

int main() {

  int n,x;
  cin>>n>>x;

  const int mod = 1e9+7;

  int coins[n];
  for(int i=0;i<n;i++) {
    cin>>coins[i];
  }

  vector<int> dp(1000001);

  for(int i=0;i<=x;i++) {
    dp[i]=0;
  }

  for(int i=0;i<n;i++) {
    dp[coins[i]]=1;
  }

  for(int i=1;i<=x;i++) {
    for(int j=0;j<n;j++) {
      if(i>coins[j]) {
        if(dp[i-coins[j]]!=0) {
          dp[i]=(dp[i]+dp[i-coins[j]])%mod;
        }
      }
    }
  }

  cout<<dp[x]%mod<<endl;

  return 0;
}
