//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

/*
https://cses.fi/problemset/task/1140
*/

long long max(long long a, long long b) {
  if(a>b) {
    return a;
  }

  return b;
}

int main() {

  long long int n;
  cin>>n;

  long long int start[n];
  long long int end[n];
  long long int coins[n];

  map<long long int,pair<long long int,long long int> > m;

  for(long long int i=0;i<n;i++) {
    long long int s,e,c;
    cin>>s>>e>>c;

    m[e] = make_pair(s,c);
  }

  long long int temp=0;
  for(auto x: m) {

    start[temp] = x.second.first;
    end[temp] = x.first;
    coins[temp++] = x.second.second;

  }



  vector<long long int> dp(n);
  long long int ans=0;
  for(long long int i=0;i<n;i++) {
    dp[i] = coins[i];

    ans=max(ans,dp[i]);
  }




  for(long long i=1;i<n;i++) {
    for(long long j=0;j<i;j++) {
      if(end[j]<start[i]) {
        dp[i] = max(dp[i],coins[i]+dp[j]);
        ans=max(ans,dp[i]);
      }
    }
  }

  for(auto x: dp) {
    cout<<x<<" ";
  }

  return 0;
}
