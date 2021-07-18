//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

void generate_subsequence(int i, vector<int> v, list<int> subsequence) {


  if(i==v.size()) {

    return;
  }

  for(auto x: subsequence) {
    cout<<x<<" ";
  }
  cout<<endl;



  //either include this ith element in the subsequence
  subsequence.push_back(v[i]);
  generate_subsequence(i+1,v,subsequence);

  //or discard this ith element
  subsequence.pop_back();
  // generate_subsequence(i+1,v,subsequence);

}

int main() {

  vector<int> v(3);

  for(int i=0;i<3;i++) {
    v.push_back(i+1);
  }

  list<int> subsequence;

  generate_subsequence(0,v,subsequence);



  return 0;
}
