//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

/*
Given a floor of size n x m. Find the number of ways to tile the floor with tiles of size 1 x m .
A tile can either be placed horizontally or vertically.
*/

int no_of_ways(int n, int m) {

  if(n==1 || n<m) {
    return 1;
  }

  if(n==m) {
    return 2;
  }


  int op1=0,op2=0;

  //op1:- place the tile vertically
  if(n-1>=0) {
     op1 = no_of_ways(n-1,m);
  }
  //op2:- place the tile horizontally
  if(n-m>=0) {
     op2 = no_of_ways(n-m,m);
  }

  return op1+op2;
}

void solve() {
  int n,m;
  cin>>n>>m;

  cout<<no_of_ways(n,m)<<endl;
}

int main() {

  int t;
  cin>>t;
  while(t--) {
    solve();
  }

  return 0;
}
