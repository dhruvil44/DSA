//Author: Dhruvil Patel

#include<bits/stdc++.h>

using namespace std;

//https://www.spoj.com/problems/AGGRCOW/

bool check(int stalls[],int n,int cows,int mid) {

  int last_cow=stalls[0];
  int ans=1;

  for(int i=1;i<n;i++) {
    if(stalls[i]-last_cow>=mid) {
      last_cow=stalls[i];
      ans++;
      if(ans==cows) {
        return true;
      }
    }
  }
  return false;
}

int main() {

  int n,cows;
  cin>>n>>cows;

  int stalls[n];
  for(int i=0;i<n;i++) {
    cin>>stalls[i];
  }

  //Logic
  sort(stalls,stalls+n);

  int start=0;
  int end=stalls[n-1]-stalls[0];
  int ans=-1;
  while(start<=end) {
    int mid = (start+end)/2;

    bool isPossibleToPlaceCows = check(stalls,5,cows,mid);

    if(isPossibleToPlaceCows) {
      start=mid+1;
      ans=mid;
    }

    else{
      end=mid-1;
    }

  }

  cout<<ans<<endl;

  return 0;
}
