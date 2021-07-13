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


int longestSubarrayOf1(int i, vector<int> arr, int n, int k) {

  if(i==n) {

    //find the longest subarray of 1s and return it.
    int max_ones=INT_MIN;
    int ones=0;
    for(int j=0;j<n;j++) {
      if(arr[j]==1) {
        ones++;
      }
      else{
        max_ones = max(max_ones,ones);
        ones=0;
      }
    }

    max_ones = max(max_ones,ones);

    return max_ones;
  }

  if(k==0) {
    //find the longest subarray of 1s and return it.
    int max_ones=INT_MIN;
    int ones=0;
    for(int j=0;j<n;j++) {
      if(arr[j]==1) {
        ones++;
      }
      else{
        max_ones = max(max_ones,ones);
        ones=0;
      }
    }

    max_ones = max(max_ones,ones);

    return max_ones;
  }


  int op1=INT_MIN,op2=INT_MIN;
  if(arr[i]==0) {

    //option1 := to flip this current 0
    arr[i] = 1;
    op1 = longestSubarrayOf1(i+1,arr,n,k-1);


    //option2 := not to flip this current 0
    arr[i] = 0;
    op2 = longestSubarrayOf1(i+1,arr,n,k);

  }

  else{
    return longestSubarrayOf1(i+1,arr,n,k);
  }


  return max(op1,op2);


}



int main() {

  int n = 10;
  vector<int> arr(n);
  for(int i=0;i<n;i++) {
    cin>>arr[i];
  }

  int k =2;

  cout<<longestSubarrayOf1(0,arr,n,k);

  //This can be also done using 2pointer (Sliding window) approach in O(N) time.


  return 0;
}
