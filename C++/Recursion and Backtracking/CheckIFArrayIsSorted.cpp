//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

bool is_sorted(int a[], int n) {

  if(n<=1) {
    return true;
  }

  //if the current element is less than or equal to the next element and the remaining array is sorted then return true
  if(a[0]<=a[1] and is_sorted(a+1,n-1)) {
    return true;
  }

  return false;

}


// divide array in 2 parts and check,
// both the divided arrays are sorted and the last element of the first array is less than
// or equal to the first element of the second array then return true. 
bool is_sorted_method2(int i, int j, int a[]) {

  if(j<=i) {
    return true;
  }

  int mid = (i+j)/2;

  if(is_sorted_method2(i,mid,a) and is_sorted_method2(mid+1,j,a) and a[mid]<=a[mid+1]) {
    return true;
  }

  return false;

}

int main() {

  int arr[] = {1,2,3,4,5,6,7};
  int arr1[] = {1,2,3,4,2,2,1};

  int n = sizeof(arr)/sizeof(int);
  cout<<is_sorted(arr,n)<<endl;

  n = sizeof(arr1)/sizeof(int);
  cout<<is_sorted(arr1,n)<<endl;


  cout<<is_sorted_method2(0,n,arr)<<endl;
  cout<<is_sorted_method2(0,n,arr1)<<endl;
  return 0;
}
