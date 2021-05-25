//Author: Dhruvil Patel

#include<bits/stdc++.h>

using namespace std;

//Given 2N+1 integers where all numbers are occuring twice except a single number which is unique.
//Find that unique number

int main() {

  int a[] = {1,2,33,2,33,1,44,5,5};
  int n = sizeof(a)/sizeof(int);

  int ans=0;
  for(int i=0;i<n;i++) {
    ans=ans^a[i];   //Bitwise XOR Operation
  }

  cout<<ans<<endl;

  return 0;
}
