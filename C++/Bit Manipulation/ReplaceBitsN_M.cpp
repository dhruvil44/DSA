//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

//You are given 2 32-bit numbers, N and M, and you are Given
// 2 positions of bit i and j.
//Write a method to set all bits between i and j in N equal to M.
//Example:-

// N=10000000000
// M=10101 i=2, j=6

// Output = 10001010100

int clearBitsInRangeFromIToJ(int n,int i,int j) {
  int a = (~0)<<(j+1);
  int b = (1<<i)-1;
  int mask = a|b;

  int ans = n&mask;
  return ans;
}

int main() {

  int n,m;
  cin>>n>>m;

  int i,j;
  cin>>i>>j;

  int n_ = clearBitsInRangeFromIToJ(n,i,j);

  int mask = (m<<i);

  cout<<(n_|mask)<<endl;

  return 0;
}
