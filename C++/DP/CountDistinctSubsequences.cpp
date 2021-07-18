//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;



/*
https://www.youtube.com/watch?v=9UEHPiK53BA
*/

//Given a string, count the number of distinct subsequences of it ( including empty subsequence ).
//Input = ABA
//Output = 7 ("","A","B","AB","BA","AA","ABA")


int distinct_subsq(string str) {


  int dp[str.size()+1];
  dp[0]=1;

  map<char,int> mp;

  for(int i=1;i<=str.size();i++) {

    dp[i] = 2*dp[i-1];
    if(mp.find(str[i-1])!=mp.end()) {
      int idx = mp[str[i-1]];
      int prev_idx = idx - 1;
      dp[i] = dp[i] - dp[prev_idx];
    }

    mp[str[i-1]]=i;
  }

  return dp[str.size()];
}

int main() {

  string str = "ABA";

  cout<<distinct_subsq(str);


  return 0;
}
