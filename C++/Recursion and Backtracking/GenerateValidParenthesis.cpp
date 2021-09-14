//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

void generate(int n, char *s, int idx, int open, int close) {

  if(idx==2*n) {
    s[idx] = '\0';
    cout<<s<<endl;
    return;
  }

  if(close<open) {
    s[idx] = ')';
    generate(n,s,idx+1,open,close+1);
  }

  if(open<n) {
    s[idx] = '(';
    generate(n,s,idx+1,open+1,close);
  }
  return;
}


int main() {

  char s[1000];
  int idx=0;
  s[0] = '(';
  idx++;
  int open=1;
  int close=0;
  generate(3,s,idx,open,close);

  return 0;
}
