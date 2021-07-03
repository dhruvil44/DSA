//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;


/*
https://cses.fi/problemset/task/1093
*/


int main() {

  int n;
  cin>>n;

  int sum = (n*(n+1))/2;

  if(sum&1) {
    cout<<"0\n";
  }

  else{
    sum=sum/2;

    int dp[n][sum+1];

    dp[0][0]=1;

    //init first col with 1
    for(int i=0;i<=n;i++) {
      dp[i][0]=1;
    }

    const int mod = 1e9+7;

    for(int i=1;i<n;i++) {
      for(int j=1;j<=sum;j++) {
        if(j>=i) {
          dp[i][j] = (dp[i-1][j] + dp[i-1][j-i])%mod;
        }
        else{
          dp[i][j] = dp[i-1][j];
        }
      }
    }

      cout<<(dp[n][sum])%mod;
  }



  return 0;
}
