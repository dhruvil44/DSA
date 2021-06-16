//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

/*
https://cses.fi/problemset/task/1634
*/

int main() {


  int n,x;
  cin>>n>>x;

  long int coins[n];
  for(int i=0;i<n;i++) {
    cin>>coins[i];
  }

  vector<int> dp(1000001);
  for(int i=0;i<=x;i++) {
    dp[i] = INT_MAX;
  }

  for(int i=0;i<n;i++) {
    dp[coins[i]]=1;
  }

  for(int i=1;i<=x;i++) {
    for(int j=0;j<n;j++) {
      if(coins[j]<i) {
        if(dp[i-coins[j]]!=INT_MAX) {
          dp[i]=min(dp[i],dp[i-coins[j]]+1);
        }
      }
    }
  }

  if(dp[x]==INT_MAX) {
    cout<<"-1\n";
  } else{
    cout<<dp[x]<<"\n";
  }

  return 0;
}
