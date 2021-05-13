//Author: Dhruvil Patel

//Given a sorted array find the first and last occurence of a given element.


#include<bits/stdc++.h>

using namespace std;

int firstOccurence(int a[], int n, int key) {

  int ans=-1;
  int start=0;
  int end=n-1;

  while(start<=end) {
    int mid = (start+end)/2;

    if(key>a[mid]) {
      start=mid+1;
    }
    else if(key<a[mid]) {
      end=mid-1;
    }
    else{
      ans=mid;
      end=mid-1;
    }
  }

  return ans;
}

int lastOccurence(int a[], int n, int key) {

  int ans=-1;
  int start=0;
  int end=n-1;

  while(start<=end) {
    int mid = (start+end)/2;

    if(key>a[mid]) {
      start=mid+1;
    }
    else if(key<a[mid]) {
      end=mid-1;
    }
    else{
      ans=mid;
      start=mid+1;
    }
  }

  return ans;
}

int main() {

  int a[] = {1,2,3,4,4,4,4,4,4,5,60};
  int n=11;

  cout<<firstOccurence(a,n,4)<<endl;
  cout<<lastOccurence(a,n,4)<<endl;



  return 0;
}
