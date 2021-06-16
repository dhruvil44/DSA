//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

int main() {


  int a = 10;
  cout<< &a <<endl;

  float b = 10.23;
  cout<< &b <<endl;


  //however there is an exeption while working with & operator with char data type.
  //This is due to operator overloading. hence we need to explicitly typecast it.
  char c = 'A';
  cout<< (void *)&c <<endl;


  return 0;
}
