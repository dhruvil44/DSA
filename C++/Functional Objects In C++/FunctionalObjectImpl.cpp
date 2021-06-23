//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

class Fun {

public:
  //Overloading "()" operator
  void operator()(string s) {
    cout<<"Having fun with "<<s<<endl;
  }
};


int main() {

  Fun f;
  f("C++"); //Here f is an object but it looks like a function...thats why its also called as functor.
  

  return 0;
}
