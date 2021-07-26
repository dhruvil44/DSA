//Author: Dhruvil Patel
#include<bits/stdc++.h>
using namespace std;

//Given N. Find all valid pair parenthesis.
// Ex:- N=3
// Output:-  ((()))
//           (()())
//           (())()
//           ()(())
//           ()()()


//To count the number of valid parenthesis we can use catalan number formula.

//To generate all valid parenthesis we can use recursion but here we will use queue with same time complexity.

//The intuition is in a given string we can either append ')' or '(' by checking some conditions.

void generate_parenthesis(int n) {

  queue<string> q;
  vector<string> ans;

  q.push("(");

  while(!q.empty()) {
    string s = q.front();
    q.pop();

    int open_bracs=0;
    int close_bracs=0;

    for(auto x: s) {
      if(x==')') {
        close_bracs++;
      }
      else{
        open_bracs++;
      }
    }

    if(close_bracs==n and open_bracs==n) {
      ans.push_back(s);
    }

    if(close_bracs==open_bracs and open_bracs<n) {
      string s1 = s;
      s1+='(';
      q.push(s1);
    }

    else if(open_bracs<n) {
      string s2 = s;
      s2+='(';
      q.push(s2);
    }

    if(open_bracs>close_bracs) {
      string s3 = s;
      s3+=')';
      q.push(s3);
    }

  }

  for(auto str: ans) {
    cout<<str<<endl;
  }

}

int main() {

  int n = 3;
  generate_parenthesis(n);


  return 0;
}
