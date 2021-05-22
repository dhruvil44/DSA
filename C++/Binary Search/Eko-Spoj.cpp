//Author: Dhruvil Patel

#include<bits/stdc++.h>

using namespace std;
//https://www.spoj.com/problems/EKO/

bool check(vector<long long int> v, long long int n, long long int m, long long int mid) {
  long long int cut_trees=0;
  for(auto x:v) {
    if(mid<x) {
      cut_trees+=x-mid;
    }
  }

  if(cut_trees>=m) {
    return true;
  }

  return false;
}

int main() {

  long long int n,m;
  cin>>n>>m;
  long long int maxi=LLONG_MIN;

  vector<long long int> v(n);

  for(long long int i=0;i<n;i++) {
    cin>>v[i];
    maxi=max(maxi,v[i]);
  }


  //LOGIC
  long long int start=0;
  long long int end = maxi;
  long long int ans;

  while(start<=end) {
    long long int mid = (start+end)/2;

    bool is_possible_to_cut_trees = check(v,n,m,mid);

    if(is_possible_to_cut_trees) {
        ans=mid;
        start=mid+1;
    }
    else{
      end=start-1;
    }
  }

  cout<<ans<<endl;
  return 0;
}
