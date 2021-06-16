//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

/*
https://cses.fi/problemset/task/1636
*/

int main() {

  int n,x;
  cin>>n>>x;

  const int mod = 1e9+7;

  int coins[n];
  for(int i=0;i<n;i++) {
    cin>>coins[i];
  }

   vector<vector<int>> dp(n+1,vector<int>(x+1,0));

   //Initializing first col with 1
   for(int i=0;i<=n;i++) {
     dp[i][0]=1;
   }



   for(int i=1;i<=n;i++) {
     for(int j=1;j<=x;j++) {
       dp[i][j] = dp[i-1][j];

       if(j>=coins[i-1]) {
         dp[i][j] = (dp[i][j] + dp[i][j-coins[i-1]])%mod;
       }
     }
   }

   cout<<dp[n][x]%mod<<endl;
  return 0;
}
