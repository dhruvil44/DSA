//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> p1, pair<int,int> p2) {
  return p1.second <= p2.second;
}

void solve() {
  int n;
  cin>>n;
  vector<pair<int,int> >v;

  for(int i=0;i<n;i++) {
      int s,e;
      cin>>s>>e;

      v.push_back(make_pair(s,e));
  }

  sort(v.begin(),v.end(),compare);

  int activities=1;
  int last_finish_time = v[0].second;

  for(int i=1;i<n;i++) {
    if(v[i].first>=last_finish_time) {
      last_finish_time=v[i].second;
      activities++;
    }
  }

  cout<<activities<<endl;
  v.clear();
}

int main() {

  int t;
  cin>>t;

  while(t--) {
    solve();
  }


  return 0;
}
