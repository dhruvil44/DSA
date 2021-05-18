//Author: Dhruvil Patel

#include <bits/stdc++.h>

using namespace std;

template<typename T>
int search(T a[], int n, T key) {
  for(int i=0;i<n;i++) {
    if(a[i]==key) {
      return i;
    }
  }

  return -1;
}

int main() {


  int a[] = {1,2,3,4,5};
  int n=5;
  int key=4;
  cout<<search(a,n,key)<<endl;

  string b[] = {"hello","titanic","batman","tenet"};
  n=4;
  string string_key="titanic";
  cout<<search(b,n,string_key)<<endl;

  return 0;
}
