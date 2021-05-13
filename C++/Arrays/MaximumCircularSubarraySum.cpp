//Author: Dhruvil Patel

//You are provided n numbers (both +ve and -ve).
//Numbers are arranged in a circular form.
//You need to find the maximum sum of consecutive numbers.

#include<bits/stdc++.h>

using namespace std;

int main() {


  int a[] = {8,-8,9,-9,10,-11,12};

  int n = 7;

  //Logic

  //First find simple subarray sum using kadane's algo
  int sum=0;
  int kadaneAns=0;
  for(int i=0;i<n;i++) {
    sum=max(sum+a[i],a[i]);
    kadaneAns=max(kadaneAns,sum);
  }


  int prefixSum[n];
  prefixSum[0]=a[0];
  for(int i=1;i<n;i++) {
    prefixSum[i] = prefixSum[i-1]+a[i];
  }

  int suffixSum[n];
  suffixSum[n-1]=a[n-1];
  for(int i=n-2;i>=0;i--) {
    suffixSum[i] = suffixSum[i+1]+a[i];
  }

  int maxSuffixTillNow[n];
  maxSuffixTillNow[n-1]=suffixSum[n-1];

  for(int i=n-2;i>=0;i--) {
    maxSuffixTillNow[i]=max(maxSuffixTillNow[i+1],suffixSum[i]);
  }

  int prefixSuffixApproachAns=INT_MIN;
  for(int i=0;i<n-1;i++) {
    prefixSuffixApproachAns=max(prefixSuffixApproachAns,prefixSum[i]+maxSuffixTillNow[i+1]);
  }


  cout<<max(prefixSuffixApproachAns,kadaneAns);

  return 0;
}
