
#include<bits/stdc++.h>
using namespace std;

//https://cses.fi/problemset/task/1638

int main() {

  const int mod = 1e9 + 7;

  int n;
  cin>>n;

  char grid[1000][1000];

  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      cin>>grid[i][j];
    }
  }

  int dp[1000][1000];
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      dp[i][j]=0;
    }
  }

  //Initializing first row
  for(int i=0;i<n;i++) {
    if(grid[0][i]=='*') {
      break;
    }
    else {
      dp[0][i]=1;
    }
  }

  //Initializing first col
  for(int i=0;i<n;i++) {
    if(grid[i][0]=='*') {
      break;
    }

    else{
      dp[i][0]=1;
    }
  }

  for(int i=1;i<n;i++) {
    for(int j=1;j<n;j++) {
      if(grid[i][j]=='*') {
        dp[i][j]=0;
      }
      else{
        dp[i][j] = (dp[i-1][j] + dp[i][j-1])%mod;
      }
    }
  }

  cout<<(dp[n-1][n-1])%mod<<endl;

  return 0;
}
