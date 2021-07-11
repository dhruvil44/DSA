//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

//Given a Rod of length N and we need to cut this rod into some smaller lengths such that
//the profit is maximum.

/*
https://www.geeksforgeeks.org/cutting-a-rod-dp-13/
*/

int max_profit_recursion(int lengths[],int profits[], int n, int length) {

    if(length==0) {
      return 0;
    }

    int ans = INT_MIN;
    for(int i=0;i<n;i++) {
      int cut = lengths[i];
      int curr_ans;
      if(length-cut>=0) {
        curr_ans = profits[i] + max_profit_recursion(lengths,profits,n,length-cut);
      }

      ans = max(ans,curr_ans);
    }

  return ans;
}


int max_profit_bottomUp(int lengths[], int profits[], int n, int length) {
  int dp[100]={0};


  for(int len=1;len<=length;len++) {
      for(int i=0;i<n;i++) {
        if(lengths[i]<=len) {
            int cut = lengths[i];
            dp[len] = max(dp[len], profits[i] + dp[len-cut]);
        }
      }
  }

  return dp[length];
}


int main() {

  int length = 8; //length of the rod
  int lengths[] = {1,2,3,4,5,6,7,8}; //the possible cuts we can make on the rod
  int profits[] = {1,5,8,9,10,17,17,20}; //the profits we get by making respective cuts on the rod
  int profits1[] = {3,5,8,9,10,17,17,20};

  cout<<max_profit_recursion(lengths,profits1,8,length)<<endl;

  cout<<max_profit_bottomUp(lengths,profits,8,length)<<endl;
  cout<<max_profit_bottomUp(lengths,profits1,8,length)<<endl;

  return 0;
}
