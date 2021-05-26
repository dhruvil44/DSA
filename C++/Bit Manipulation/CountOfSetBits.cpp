//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

//Given a number N, find the count of set bits in it.
//Example : N=13 (1011)
//Output:- 3

//Example : N=15 (1111)
//Output:- 4

int countSetBits(int n) {
  int ans=0;

  while(n>0) {
    ans += (n&1);
    n = (n>>1);
  }

  return ans;
}


int countSetBitsFaster(int n) {
  int ans=0;

  while(n>0) {
    n = n&(n-1);
    ans++;
  }

  return ans;
}

int main() {

  int n;
  cin>>n;

  cout<<countSetBits(n)<<endl;
  cout<<countSetBitsFaster(n)<<endl;

  //built in function
  cout<<__builtin_popcount(n)<<endl;

  return 0;
}
