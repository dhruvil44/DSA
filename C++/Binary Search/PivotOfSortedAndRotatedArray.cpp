//Author: Dhruvil Patel

#include<bits/stdc++.h>

using namespace std;

int main() {

  int n;
  cin>>n;

  int a[n];
  for(int i=0;i<n;i++) {
    cin>>a[i];
  }

  int start=0;
  int end=n-1;
  int ans;
  while(start<=end) {
    int mid = (start+end)/2;

    if(a[mid]>=a[start]) {

      if(a[mid]>a[mid+1]) {
        ans=mid;
        break;
      }

      start=mid+1;

    } else{
      end=mid-1;
    }


  }

  cout<<ans<<endl;

  return 0;
}
