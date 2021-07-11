//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

/*
https://www.geeksforgeeks.org/friends-pairing-problem/
*/

int no_of_ways_to_pair(int no_of_friends) {

  if(no_of_friends<=0) {
    return 0;
  }

  else if(no_of_friends<=2) {
    return no_of_friends;
  }
  //if the nth friend is not paired with anyone   if the nth friend is paired with any n-1 friends and then we find the answer for remaining n-2 friends.
  return no_of_ways_to_pair(no_of_friends-1) + (no_of_friends-1)*no_of_ways_to_pair(no_of_friends-2);
}


int bottom_up_approach(int no_of_friends) {

  int dp[no_of_friends+1];

  dp[0]=1;
  dp[1]=1;

  for(int i=2;i<=no_of_friends;i++) {
    dp[i] = dp[i-1] + (i-1)*dp[i-2];
  }

  return dp[no_of_friends];

}

int main() {


  int no_of_friends = 4;

  cout<<no_of_ways_to_pair(no_of_friends)<<endl;

  cout<<bottom_up_approach(no_of_friends)<<endl;


  return 0;
}
