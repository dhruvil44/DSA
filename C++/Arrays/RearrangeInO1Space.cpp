//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

/*
A very interesting problem.

Link:-
https://practice.geeksforgeeks.org/problems/rearrange-an-array-with-o1-extra-space3142/1/?company[]=Amazon&company[]=Amazon&problemStatus=unsolved&page=2&query=company[]AmazonproblemStatusunsolvedpage2company[]Amazon#


Given an array arr[] of size N where every element is in the range from 0 to n-1.
Rearrange the given array so that arr[i] becomes arr[arr[i]].


Input:
N = 5
arr[] = {4,0,2,1,3}
Output: 3 4 2 0 1

*/

void rearrange(int a[], int n) {


    for(int i=0;i<n;i++) {

      //getting the current value of a[i]
      int curr_num = a[i];
      //getting the new value which is to be stored at a[i].
      int new_num = a[a[i]]%n;

      //saving the data at a[i] such that both the old and new number gets stored.
      a[i] = n*new_num + curr_num;
      //so if we want to get the older number at a[i] we do a[i]%n and
      //if we want the new number that is stored at a[i] we do a[i]/n;

    }

    for(int i=0;i<n;i++) {
      //updating all the values with new values
      a[i] = a[i]/n;
    }


}


int main() {

  int a[] = {4,0,2,1,3};
  int n = sizeof(a)/sizeof(int);

  cout<<"Original Array\n";
  for(int i=0;i<n;i++) {
    cout<<a[i]<<" ";
  }
  cout<<endl<<endl;

  rearrange(a,n);

  cout<<"Updated Array\n";
  for(int i=0;i<n;i++) {
    cout<<a[i]<<" ";
  }

  return 0;
}
