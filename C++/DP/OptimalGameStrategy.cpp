//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;


//Given a array of points and 2 players A and B.
//A takes first chance.
//Both the players can choose any number from the extreme ends and it will add up to their points.
//Both players play optimally.
//Find out the maximum points A can gain.


//Recursive helper
int helper(int i, int j, int a[]) {

  if(i>j) {
    return 0;
  }

  //if the player1 selects the ith element
  int option1 = a[i] + min(helper(i+2,j,a),helper(i+1,j-1,a));

  //if the player1 selects the jth element
  int option2 = a[j] + min(helper(i+1,j-1,a),helper(i,j-2,a));

  return max(option1,option2);


}

//Recursive
int max_points(int a[], int n) {


  return  helper(0,n-1,a);

}



//Top Down DP Helper
int helper_top_down(int i, int j, int a[], int dp[][100]) {

  if(i>j) {
    return 0;
  }

  //lookup
  if(dp[i][j]!=0) {
    return dp[i][j];
  }

  //if the player1 selects the ith element
  int option1 = a[i] + min(helper(i+2,j,a),helper(i+1,j-1,a));

  //if the player1 selects the jth element
  int option2 = a[j] + min(helper(i+1,j-1,a),helper(i,j-2,a));

  return dp[i][j] = max(option1,option2);


}

//Top Down DP
int max_points_top_down(int a[], int n, int dp[][100]) {

  return helper_top_down(0,n-1,a,dp);

}

int main() {

  int a[] = {7,10,4,6};
  int n = sizeof(a)/sizeof(int);
  cout<<max_points(a,n)<<endl; //Recursive


  int dp[100][100] ={0};
  cout<<max_points_top_down(a,n,dp)<<endl; //Top Down DP


  return 0;
}
