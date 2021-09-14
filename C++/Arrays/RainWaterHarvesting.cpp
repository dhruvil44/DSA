//Author: Dhruvil Patel
/*
https://leetcode.com/problems/trapping-rain-water/
*/
#include<bits/stdc++.h>

using namespace std;

int main() {


  int a[] = {0,2,1,3,0,1,2,1,2,1};
  int n = 10;


  //Logic
  int leftHighBuildingPrefix[10];
  int rightHighBuildingSuffix[10];

  leftHighBuildingPrefix[0] = a[0];
  rightHighBuildingSuffix[n-1] = a[n-1];

  for(int i=1;i<n;i++) {
    leftHighBuildingPrefix[i] = max(leftHighBuildingPrefix[i-1],a[i]);
  }

  for(int i=n-2;i>=0;i--) {
    rightHighBuildingSuffix[i] = max(rightHighBuildingSuffix[i+1],a[i]);
  }

  int ans=0;

  for(int i=0;i<n;i++) {
    ans+=min(leftHighBuildingPrefix[i],rightHighBuildingSuffix[i]) - a[i];
  }


  cout<<ans<<endl;

  return 0;
}
