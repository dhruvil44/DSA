//Author: Dhruvil Patel

#include<bits/stdc++.h>

using namespace std;

//https://leetcode.com/problems/search-in-rotated-sorted-array/


int main() {

  int n;
  cin>>n;

  int a[n];
  for(int i=0;i<n;i++) {
    cin>>a[i];
  }

  int start=0;
  int end=n-1;

  int key;
  cin>>key;

  while(start<=end) {
    int mid = (start+end)/2;


    if(a[mid]==key) {
      cout<<mid<<endl;
      break;
    }

    //if it lies in the first part
    if(a[start]<=a[mid]) {
      if(a[start]<=key && key<=a[mid]) {
        end=mid-1;
      } else{
        start=mid+1;
      }
    } else{
      if(key>=a[mid] && key<=a[end]) {
        start=mid+1;
      } else{
        end=mid-1;
      }
    }
  }


  return 0;
}
