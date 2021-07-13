//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;


//Count the total number of ways a BST can be formed using N nodes(1,2,3,4....N).
//Catalan Number:- 2NcN/(N+1);


int total_ways_bst(int n) {

  if(n==0 || n==1) {
    return 1;
  }

  int ans=0;

  //for every node we try to make it the root node
  for(int i=1;i<=n;i++) {

    //if i is the root node then all the i-1 nodes will form the left subtree
    int totalLeftSubtrees = total_ways_bst(i-1);

    //all the i+1..N nodes will form the right subtree
    int totalRightSubtrees = total_ways_bst(n-i);


    ans = ans + totalLeftSubtrees*totalRightSubtrees;
  }


  return ans;
}



int total_ways_bst_top_down(int n, int dp[]) {

  if(n==0 || n==1) {
    return dp[n]=1;
  }

  //lookup
  if(dp[n]!=0) {
    return dp[n];
  }

  int ans=0;

  //for every node we try to make it the root node
  for(int i=1;i<=n;i++) {

    //if i is the root node then all the i-1 nodes will form the left subtree
    int totalLeftSubtrees = total_ways_bst(i-1);

    //all the i+1..N nodes will form the right subtree
    int totalRightSubtrees = total_ways_bst(n-i);


    ans = ans + totalLeftSubtrees*totalRightSubtrees;
  }


  return dp[n] = ans;


}

int main() {


  cout<<total_ways_bst(3)<<endl; //Recursive approach

  int dp[1000]={0};
  cout<<total_ways_bst_top_down(3,dp)<<endl; //Top-Down DP

  //This can also be directly solved using Catalan Number Formula.

  return 0;
}
