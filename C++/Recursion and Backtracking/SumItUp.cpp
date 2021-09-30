//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;


/*

You are given an array of numbers and a target number(T) ,
print all unique combinations in the array whose sum equals the target number T.
Note that each number in the array may only be used once in the combination.

Input:-
7
10 1 2 7 6 1 5
8

Output:-
1 1 6
1 2 5
1 7
2 6


*/

void get_combinations(int a[], int n, int i, int sum,
                      int target, vector<int> v, set<vector<int> > &st) {

  if(sum==target) {
    sort(v.begin(),v.end());
    st.insert(v);
    return;
  }

  if(i==n) {
    return;
  }

  //either to discard this element and move ahead
  get_combinations(a,n,i+1,sum,target,v,st);

  //or to include this element
  v.push_back(a[i]);
  get_combinations(a,n,i+1,sum+a[i],target,v,st);

}

int main() {

  int a[] = {10,1,2,7,6,1,5};
  int n = sizeof(a)/sizeof(int);
  int target = 8;

  vector<int> v;
  set<vector<int> >st;
  int sum=0;
  get_combinations(a,n,0,sum,target,v,st);


  for(auto v: st) {
    for(auto x:v){
      cout<<x<<" ";
    }
    cout<<endl;
  }

  return 0;
}
