//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

//Given problem is almost similar to the knapsack 0-1 problem but with 1 difference.
//Here we could pick any item multiple times.
//We have infinite supply of all items and we can take any item for anytimes we want to maximize the value.

//Example:-
// n=5 , knapsack = 11
// weights[] = 3 2 4 5 1
// values[] = 4 3 5 6 1

//Output:- 16

//We take second item 4 times and fifth item one time to make the total values 16.

int knapsack_soln(int weights[], int values[], int n, int knapsack) {

  int dp[knapsack+1]={0};
  dp[0]=0;

  int ans=INT_MIN;

  for(int i=1;i<=knapsack;i++) {
    for(int j=0;j<n;j++) {
      if(i>=weights[j]) {
        dp[i] = max(dp[i],values[j]+dp[i-weights[j]]);
      }
    }

    ans=max(ans,dp[i]);
  }

  return ans;
}


int main() {

  int n=5;
  int knapsack = 11;

  int weights[] = {3,2,4,5,1};
  int values[] = {4,3,5,6,1};

  cout<<knapsack_soln(weights,values,n,knapsack)<<endl;

  return 0;
}
