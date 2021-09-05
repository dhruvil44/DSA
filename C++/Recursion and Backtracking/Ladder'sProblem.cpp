//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

/*
Given a ladder with N steps.
The maximum steps you can take is 1,2,3.
Count the number of ways to reach at the top.
*/

int no_of_ways(int n) {

  //already at the ground
  if(n==0) {
    return 1;
  }

  if(n<0) {
    return 0;
  }

  int ans = no_of_ways(n-1) + no_of_ways(n-2) + no_of_ways(n-3);
  return ans;

}


int main() {


  cout<<no_of_ways(4)<<endl;

  return 0;
}
