//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

int find_idx(int i, int j ,int a[], int key) {

  if(i>j) {
    return -1;
  }

  int mid = (i+j)/2;

  if(a[mid] == key) {
    return mid;
  }

  if(a[mid] < key) {
    return find_idx(mid+1,j,a,key);
  }

    return find_idx(i,mid-1,a,key);
}


int main() {

  int arr[] = {2,3,4,4,5,66,345};
  int n = sizeof(arr)/sizeof(int);

  cout<<find_idx(0,n,arr,2)<<endl;
  cout<<find_idx(0,n,arr,3)<<endl;
  cout<<find_idx(0,n,arr,4)<<endl;
  cout<<find_idx(0,n,arr,5)<<endl;
  cout<<find_idx(0,n,arr,66)<<endl;
  cout<<find_idx(0,n,arr,345)<<endl;


  return 0;
}
