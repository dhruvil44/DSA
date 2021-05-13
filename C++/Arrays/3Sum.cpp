//Author: Dhruvil Patel

#include<bits/stdc++.h>

using namespace std;

int main() {


  int a[] = {5,7,9,1,2,4,6,8,3};
  int n = 9;

  int targetSum=10;



  //Logic
  sort(a,a+n);

  for(int i=0;i<n-2;i++) {
    int l=i+1;
    int r=n-1;
    int sum = targetSum-a[i];

    while(l<r) {
      if(sum>a[l]+a[r]) {
        l++;
      }
      else if(sum<a[l]+a[r]) {
        r--;
      }

      else{
        cout<<a[i]<<", "<<a[l]<<", "<<a[r]<<endl;
        l++;
        r--;
      }
    }
  }


  return 0;
}
