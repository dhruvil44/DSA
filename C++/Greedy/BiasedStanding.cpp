//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

//https://www.spoj.com/problems/BAISED/

void solve() {
  int n;
  cin>>n;

  int a[100000];

  memset(a,0,sizeof(a));

  for(int i=0;i<n;i++) {
    string name;
    cin>>name;

    int wished_rank;
    cin>>wished_rank;

    a[wished_rank]++;
  }

  int badness=0;
  int rank=1;

  int i=0;
  while(i<=n) {


    if(a[i]==0) {
      i++;
      continue;
    }
    badness+=abs(rank-i);
    rank++;
    a[i]--;

  }
  cout<<badness<<endl;
}

int main() {

  int t;
  cin>>t;

  while(t--) {
    solve();
  }



  return 0;
}
