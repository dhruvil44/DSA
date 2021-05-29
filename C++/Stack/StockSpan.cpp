//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

int main() {

  int stock_prices[] = {100,80,60,70,60,75,85};
  // int stock_prices[] = {100,180,260,370,460,575,585};
  int n = sizeof(stock_prices)/sizeof(int);

  stack<pair<int,int> > s;
  s.push({stock_prices[0],0});

  vector<int> ans(n,0);

  for(int i=1;i<n;i++) {
    if(stock_prices[i] <= s.top().first) {
      ans[i] = (i-s.top().second);
      s.push({stock_prices[i],i});
    }

    else{
      while(!s.empty()) {

        if(s.top().first>=stock_prices[i]) {
          ans[i] = (i-s.top().second);
          s.push({stock_prices[i],i});
          break;
        }

        s.pop();

      }

      if(s.empty()) {
        s.push({stock_prices[i],i});
      }
    }
  }

  for(auto x: ans) {
    cout<<x<<" ";
  }

  return 0;
}
