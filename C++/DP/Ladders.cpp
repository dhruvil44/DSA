//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

//Given a ladder with N steps. Find the total number of ways to reach the top of the ladder,
//given that the maximum number of steps that can be taken at a time is k.

//For ex:- N=3 , k=3
//The number of ways will be:-
//1,1,1
//1,2
//2,1
//3
//Therefore 4 number of ways.


int no_of_ways_recursion(int n, int k) {

  if(n==0) {
    return 1;
  }

  int ans=0;
  for(int i=1;i<=k;i++) {
    if(n-i>=0) {
      ans+=no_of_ways_recursion(n-i,k);
    }
  }

    return ans;
}


int no_of_ways_topDown(int n, int k, int dp[]) {

  if(n==0) {
    return 1;
  }

  //check / lookup
  if(dp[n]!=0) {
    return dp[n];
  }

  int ans=0;
  for(int i=1;i<=k;i++) {
    if(n-i>=0) {
      ans+=no_of_ways_recursion(n-i,k);
    }
  }

    return dp[n] = ans;



}

//Complexity(O(N*K))
int no_of_ways_bottomUp(int n, int k) {

  int dp[100]={0};
  dp[0] =1;

  for(int i=1;i<=n;i++) {
      for(int j=1;j<=k;j++) {
        if(i-j>=0) {
          dp[i]+=dp[i-j];
        }
      }
  }

  return dp[n];
}


//Complexity(O(N))
int no_of_ways_bottomUp_optimised(int n, int k) {
  int dp[100]={0};

  dp[0]=dp[1]=1;
  for(int i=2;i<=k;i++) {
    dp[i] = 2*dp[i-1];
  }

  for(int i=k+1;i<=n;i++) {
    dp[i] = 2*dp[i-1] - dp[i-k-1];
  }
  return dp[n];
}


int main() {

  int n=6;
  int k=3;
  cout<<no_of_ways_recursion(n,k)<<endl;

  int dp[100]={0};
  cout<<no_of_ways_topDown(n,k,dp)<<endl;

  cout<<no_of_ways_bottomUp(n,k)<<endl;

  cout<<no_of_ways_bottomUp_optimised(n,k)<<endl;

  return 0;
}
