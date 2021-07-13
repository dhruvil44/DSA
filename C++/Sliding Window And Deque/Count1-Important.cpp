//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

//Given an array of size n with 0s and 1s.
//Flip at most k 0s to get the longest possible subarray of 1s.


//Example TC:-
// n=10 k=2
// 1 0 0 1 0 1 0 1 0 1

//Output
// 5 (Longest subarray of 1s possible after flipping at most 2 zeros)
// 1 0 0 1 1 1 1 1 0 1

int main() {

  string s = "1001010101";

  int k=2;

  int l=0,r=0;
  int max_len=INT_MIN;
  string subarray = "";
  int zeros=0;

  while(r<s.length()) {
    cout<<r<<" "<<l<<endl;
    if(s[r]=='1') {

      if(max_len<(r-l+1)) {
        max_len = r-l+1;
        subarray = s.substr(l,r-l+1);
      }

    }

     if(s[r]=='0') {

      zeros++;

      while (zeros>k and l<=r) {

        if(s[l]=='0') {
          zeros--;
        }
        l++;
      }

      if(max_len<(r-l+1)) {
        max_len = r-l+1;
        subarray = s.substr(l,r-l+1);
      }

    }

    r++;

  }

  cout<<max_len<<endl;
  cout<<subarray;

  return 0;
}
