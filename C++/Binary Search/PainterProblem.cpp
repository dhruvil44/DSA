//Author: Dhruvil Patel

#include<bits/stdc++.h>

using namespace std;

// You have to paint N boards of length {A0, A1, A2, A3 … AN-1}. There are K painters available
// and you are also given how much time a painter takes to paint 1 unit of board. You have to get
// this job done as soon as possible under the constraints that any painter will only paint
// contiguous sections of board. Return the ans % 10000003


// Input Format
// First line contains three space seperated integers N,K and T ,where
// N = Size of array,
// K = No of painters available ,
// T = Time taken to print each board by one painter
// Next line contains N space seperated positive integers denoting size of N boards.

bool check(long long int a[], long long int n, long long int k, long long int t, long long int mid) {

  long long int painters=1;
  long long int time=0;

  for(long long int i=0;i<n;i++) {
    if(time + t*a[i] > t) {
      painters++;

      time = a[i]*t;

      if(painters>k) {
        return false;
      }
    } else{
      time+=t*a[i];
    }
  }

  return true;
}

int main() {


  long long int n,k,t;
  cin>>n>>k>>t;

  long long int sum=0;
  long long int boards[n];
  for(long long int i=0;i<n;i++) {
    cin>>boards[i];
    sum+=boards[i];
  }

  sort(boards,boards+n);

  long long int start=boards[n-1]*t;
  long long int end=sum*t;
  long long int ans;
  while(start<=end) {
    long long int mid = (start+end)/2;

    bool is_possible_to_paint = check(boards,n,k,t,mid);

    if(is_possible_to_paint) {
      ans = mid;
      end = mid-1;
    }
    else{
      start=mid+1;
    }
  }

  cout<<ans<<endl;

  return 0;
}
