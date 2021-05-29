//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

int main() {

  int bars[] = {6,2,5,4,5,1,6};
  int n = sizeof(bars)/sizeof(int);

  //Logic
  //Adding a bar of height 0 at the end for convinience
  bars[n]=0;
  n++;
  stack<int> stk;
  int ans=INT_MIN;

  stk.push(0);

  for(int i=1;i<=n;i++) {
    if(bars[i]>=stk.top()) {
      stk.push(i);
    }

    else{

      while(!stk.empty() and bars[stk.top()]>bars[i])
    {
      int idx = stk.top();
      stk.pop();

      if(stk.empty()) {
        ans=max(ans,(bars[idx])*(i-idx));
        break;
      }
      else{
        ans=max(ans,(bars[idx])*(i-stk.top()-1));
      }
    }

    stk.push(i);
  }
}

  cout<<ans<<endl;

  return 0;
}
