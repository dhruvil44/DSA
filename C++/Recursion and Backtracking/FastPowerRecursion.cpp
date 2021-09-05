//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

int fast_power(int a, int b) {
  if(b==0) {
    return 1;
  }

  if(b==1) {
    return a;
  }

  int small_ans = fast_power(a,b/2);
  small_ans = small_ans*small_ans;

  if(b%2==1) {
    return a*small_ans;
  }
  return small_ans;
}

int main() {


  cout<<fast_power(2,5)<<endl;

  return 0;
}
