//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

/*
Count the total number of binary strings such that there are no consecutive ones.

Ex:- N = 3 => ans = 5
      000
      001
      010
      100
      101

*/

int count(int n) {

  if(n==1) {
    return 2;
  }

  if(n==2) {
    return 3;
  }

  return count(n-1) + count(n-2);

}

int main() {

  cout<<count(4)<<endl;
  cout<<count(3)<<endl;

  return 0;
}
