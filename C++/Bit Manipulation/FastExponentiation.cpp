//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

//Find a^b

int fast_expo(int a, int b) {
  int ans=1;

  while(b>0) {
    int last_bit = (b&1);

    if(last_bit) {
      ans=ans*a;
    }

    a=a*a;
    b=(b>>1);
  }

  return ans;
}

int main() {

  cout<<fast_expo(3,4);


  return 0;
}
