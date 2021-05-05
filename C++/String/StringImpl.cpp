//Author: Dhruvil Patel

#include<bits/stdc++.h>

using namespace std;

bool compare(string a, string b) {

  if(a.length()==b.length()) {
    return a<b;
  }

  return a.length()<b.length();

}

int main() {


  string s("This is Dhruvil");
  cout<<s<<endl;


  int n=3;

  string sarr[n];

  for(int i=0;i<n;i++) {
    getline(cin,sarr[i]);
  }

  //by default sorts lexicographically
  sort(sarr,sarr+n);

  //custom
  sort(sarr,sarr+n,compare);

  for(int i=0;i<n;i++) {
    cout<<sarr[i]<<endl;
  }


  return 0;

}
