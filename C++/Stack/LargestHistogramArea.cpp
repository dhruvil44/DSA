//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

int main() {

  vector<int> bars = {6,2,5,4,5,1,6};


  //Logic
  //Adding a bar of height 0 at the end for convinience
  bars.push_back(0);
  stack<int> st;
  int n = bars.size();

  int ans = INT_MIN;

  for(int i=0;i<n;i++) {

    //this means if a bar of shorter height comes than the stack top
    while(!st.empty() and bars[st.top()]>bars[i]) {

      int height = bars[st.top()];
      st.pop();
      if(st.empty()) {
        ans = max(ans,height*i);
      }
      else{
        ans = max(ans,(i-st.top()-1)*height);
      }
    }

    st.push(i);
  }

  cout<<ans<<endl;
  return 0;
}
