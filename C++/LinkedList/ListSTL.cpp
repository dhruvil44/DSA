//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

int main() {

  list<int> l1 {1,2,3,4,5,6};

  list<string> l2 {"mark","bill","elon","jeff","ratan"};

  for(auto s: l2) {
    cout<<s<<" --> ";
  }
  cout<<endl;

  l2.sort();
  for(auto s: l2) {
    cout<<s<<" --> ";
  }
  cout<<endl;

  l2.reverse();
  for(auto s: l2) {
    cout<<s<<" --> ";
  }
  cout<<endl;


  l2.push_back("dhruvil");
  l2.push_front("mukesh");

  // l2.pop_back();
  // l2.pop_front();

  auto it = l2.begin();
  it++;
  it++;
  l2.insert(it,"steve");
  for(auto s: l2) {
    cout<<s<<" --> ";
  }
  cout<<endl;

  return 0;
}
