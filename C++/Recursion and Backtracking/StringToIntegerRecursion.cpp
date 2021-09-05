//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

//Given a string, convert it to an integer value using recursion.

int string_to_int(string s, int n) {

  //if string is empty
  if(n==0) {
    return 0;
  }

  int last_digit = s[n-1] - '0';

  int smaller_number = string_to_int(s,n-1);

  return smaller_number*10 + last_digit;
}


int main() {

  string s = "1234";
  int n = s.length();

  int x = string_to_int (s,n);
  cout<<x<<endl;
  cout<<x+10<<endl;


  return 0;
}
