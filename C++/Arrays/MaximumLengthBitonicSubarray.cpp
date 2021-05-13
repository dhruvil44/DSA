//Author: Dhruvil Patel

#include<bits/stdc++.h>

using namespace std;

int main() {

  int a[] = {12,4,78,90,45,23};
  int n=6;

  int prefixIncreasingSubarray[n];
  prefixIncreasingSubarray[0]=1;

  int suffixIncreasingSubarray[n];
  suffixIncreasingSubarray[n-1]=1;

  for(int i=1;i<n;i++) {
    if(a[i]>a[i-1]){
      prefixIncreasingSubarray[i] = prefixIncreasingSubarray[i-1]+1;
    }
    else{
      prefixIncreasingSubarray[i]=1;
    }
  }

  for(int i=n-2;i>=0;i--) {
    if(a[i]>a[i+1]) {
      suffixIncreasingSubarray[i] = suffixIncreasingSubarray[i+1]+1;
    }
    else{
      suffixIncreasingSubarray[i]=1;
    }
  }


  int ans=INT_MIN;

  for(int i=0;i<n;i++) {
    ans=max(ans,prefixIncreasingSubarray[i]+suffixIncreasingSubarray[i]-1);
  }

  cout<<ans<<endl;

  return 0;
}
