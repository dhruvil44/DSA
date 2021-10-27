//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

/*

Sort an array of 0,1 and 2 inplace without any space.

*/

void dnf(int a[], int n) {

  int low = 0;
  int mid = 0;
  int high = n-1;

  while(mid<=high) {

    if(a[mid]==0) {
      swap(a[mid],a[low]);
      low++;
      mid++;
    }

    else if(a[mid]==1) {
      mid++;
    }

    else if(a[mid]==2) {
      swap(a[mid],a[high]);
      high--;
    }

  }



}


int main() {

  int arr[] = {0,1,2,2,1,0,1};
  int n = sizeof(arr)/sizeof(int);

  dnf(arr,n);

  for(int i=0;i<n;i++) {
    cout<<arr[i]<<" ";
  }

  return 0;
}
