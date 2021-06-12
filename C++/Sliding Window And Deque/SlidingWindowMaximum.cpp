//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

//https://www.spoj.com/problems/ARRAYSUB/
//https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/


int main() {

  int n;

  int k;

  cin>>n;
  int a[n];
  for(int i=0;i<n;i++) {
    cin>>a[i];
  }

  cin>>k;

  deque<int> dq(k);

  //First of all iterate first k elements
  for(int i=0;i<k;i++) {

    while(!dq.empty() and a[i]>a[dq.back()]) {
      dq.pop_back();
    }

    dq.push_back(i);

  }


  for(int i=k;i<n;i++) {

    cout<<a[dq.front()]<<" ";

    //discard all the elements which do not belong to this window
    while(!dq.empty() and dq.front()<=i-k) {
      dq.pop_front();
    }


    //compare the current element with other elements in the deque
    while(!dq.empty() and a[i]>a[dq.back()]) {
      dq.pop_back();
    }

    dq.push_back(i);
  }

  cout<<a[dq.front()]<<" ";

  return 0;
}
