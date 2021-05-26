//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

//Given a number N, ouput its binary representation.
//Example : N=13
//Output : 1101

int decimalToBinary(int n) {
  int p=1;
  int ans=0;

  while(n>0) {
    int last_bit = n&1;

    ans+=p*last_bit;
    p*=10;

    n=(n>>1);
  }

  return ans;
}

int main() {

  cout<<decimalToBinary(13)<<endl;
  cout<<decimalToBinary(2)<<endl;
  cout<<decimalToBinary(36)<<endl;

  return 0;
}
