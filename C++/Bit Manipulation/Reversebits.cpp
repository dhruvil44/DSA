//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

//Given an integer...Reverse its bits and return the new integer

//Example :- n=13(1101)  then after reversing the bits we get 11(1011)
//           n=9(1001)   then after reversing the bits we get 9(1001)


int reverse_bits(int n) {

  int ans=0;

  while(n>0) {
    //left shift
    ans = ans<<1;

    //if the last bit is 1 then we also set our bit in the answer as 1
    if(n&1) {
      ans = ans^1;
    }

    //divide n by 2
    n = n>>1;
  }

  return ans;
}

int main() {

  int n;
  cin>>n;

  cout<<reverse_bits(n);


  return 0;
}
