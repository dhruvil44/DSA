//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;


/*
https://cses.fi/problemset/task/1145
*/

long long int max(long long int a, long long int b) {

  if(a>b) {
    return a;
  }

  return b;
}

int main() {

  long int n;
  cin>>n;

  vector<long long int> v(n);

  for(long int i=0;i<n;i++) {
    cin>>v[i];
  }

  vector<long long int> dp(n,1);
  long int ans=1;
  for(int i=1;i<n;i++) {
    for(int j=0;j<i;j++) {
      if(v[i]>v[j]) {
        dp[i] = max(dp[i],dp[j]+1);
        ans=max(ans,dp[i]);
      }
    }
  }

  cout<<ans<<endl;

  return 0;
}
