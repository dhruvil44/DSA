//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;


//Given a n*m grid. There is a rook(elephant) on the first cell and it moves similar to the chess game.
//Find out the total number of ways to reach the last cell by the Rook.

int no_of_ways(int n, int m) {

  int dp[n][m];

  dp[0][0]=1;

  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {

      if(i==0 and j==0) {
        continue;
      }

      //finding the sum of row from 0 to j-1
      int s1=0;
      for(int k=0;k<=j-1;k++) {
        s1+=dp[i][k];
      }


      //finding the sum of column from 0 to i-1
      int s2=0;
      for(int k=0;k<=i-1;k++) {
        s2+=dp[k][j];
      }

      dp[i][j] = s1+s2;
    }
  }

  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      cout<<dp[i][j]<<" ";
    }
    cout<<endl;
  }

  return dp[n-1][m-1];

}

int main() {


  int n=3,m=5;

  cout<<no_of_ways(n,m);


  return 0;
}
