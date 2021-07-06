//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

int recursiveSoln(int wines[], int i, int j, int year) {

  if(i>j) {
    return 0;
  }

  int leftBottle = wines[i]*year + recursiveSoln(wines,i+1,j,year+1);
  int rightBottle = wines[j]*year + recursiveSoln(wines,i,j-1,year+1);

  return max( leftBottle, rightBottle );

}



int topDownSoln(int wines[], int i, int j, int year, int dp[][500]) {

  if(i>j) {
    return 0;
  }

  //if its already precalculated
  if(dp[i][j]!=0) {
    return dp[i][j];
  }

  int leftBottle = wines[i]*year + recursiveSoln(wines,i+1,j,year+1);
  int rightBottle = wines[j]*year + recursiveSoln(wines,i,j-1,year+1);

  return dp[i][j] = max( leftBottle, rightBottle );

}



int bottomUpSoln(int wines[], int n) {



  int dp[n][n] = {0};

  int year = n;

  //filling all the diagonal values
  for(int i=0;i<n;i++) {
    dp[i][i] = year * wines[i];
  }

  year--;

  //filling the dp table diagonally
  for(int diff=1;diff<n;diff++) {
    for(int i=0;i<n-diff;i++) {
      int j = i + diff;

      //opting for the ith(first) bottle
      int firstBottle = wines[i]*year + dp[i+1][j];

      //opting for the jth(last) bottle
      int lastBottle = wines[j]*year + dp[i][j-1];

      dp[i][j] = max(firstBottle,lastBottle);

    }
    year--;
  }


  return dp[0][n-1];
}



int main() {

  int wines[] = {2,3,5,1,4};
  int n = sizeof(wines)/sizeof(int);


  cout<<recursiveSoln(wines,0,n-1,1)<<endl;

  int dp[500][500]={0};
  cout<<topDownSoln(wines,0,n-1,1,dp)<<endl;

  cout<<bottomUpSoln(wines,n)<<endl;

  return 0;
}
