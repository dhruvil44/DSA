//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

template<typename T>
void filter(int n, T a[]) {
  int j=0;

  while(n>0) {
    int last_bit = (n&1);

    if(last_bit) {
      cout<<a[j];
    }

    j++;
    n=(n>>1);
  }
  cout<<endl;
}

template<typename T>
void printSubsets(T a[], int len) {
  for(int i=0;i<(1<<len);i++) {
    filter(i,a);
  }
}

int main() {

  int a[] = {1,2,3};
  int len = sizeof(a)/sizeof(int);

  printSubsets(a,len);

  cout<<endl;

  char b[] = {'a','b','c','d'};
  printSubsets(b,4);
  return 0;
}
