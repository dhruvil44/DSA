//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

/*
Given N friends.They want to go to a place.
Each guy can either go single or as a couple with some other friend.
Find the total number of ways the friends can go.

Ex:- N=3 (F1,F2,F3)  => ans = 4

      F1 , F2 , F3
      (F1 , F2) , F3
      F1 , (F2 , F3)
      (F1 , F3) , F2
*/

int no_of_ways(int n) {

  if(n<1) {
    return 1;
  }

  if(n==2) {
    return 2;
  }

  return no_of_ways(n-1) + (n-1)*no_of_ways(n-2);

}

int main() {

  cout<<no_of_ways(3)<<endl;
  cout<<no_of_ways(4)<<endl;

  return 0;
}
