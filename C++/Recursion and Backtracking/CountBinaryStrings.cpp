//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

/*
Count the total number of binary strings such that there are no consecutive ones.

Ex:- N = 3 => ans = 5
      000
      001
      010
      100
      101

*/

int count(int n) {

  if(n==1) {
    return 2;
  }

  if(n==2) {
    return 3;
  }

  return count(n-1) + count(n-2);

}


void generateString(int n, string str, char prev_char) {

  if(n==0) {
    cout<<str<<endl;
    return;
  }

  //if prev char is 0 then we can have 2 options
  if(prev_char == '0') {
    //either this character can be 0
    str+='0';
    generateString(n-1, str, '0');

    //or this character can be 1
    str.pop_back();
    str+='1';
    generateString(n-1, str, '1');
  }

  //if prev char was 1 then we can only put 0 at this place because consecutive 1s are not allowed
  else {
    str += '0';
    generateString(n-1, str, '0');
  }

}


int main() {

  cout<<count(4)<<endl;
  cout<<count(3)<<endl;

  string s = "";
  generateString(4, s, '0');
  cout<<endl;
  generateString(3, s, '0');
  
  return 0;
}
