//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

/*
Take as input S, a string.
Write a function that removes all consecutive duplicates. Print the value returned.

aabccba -> abcba
*/

void remove_duplicates(char* str, int idx) {

  if(str[idx]=='\0') {
    return;
  }

  if(str[idx+1]!='\0' && str[idx]==str[idx+1]) {

    //step1:- copy all the chars one step closer
    int j = idx+1;
    while(str[j]!='\0') {
      str[j] = str[j+1];
      j++;
    }

    //step2:- recursion
    remove_duplicates(str,idx);

  }

  else{
    remove_duplicates(str,idx+1);
  }


}

int main() {

  char str[100000];
  cin>>str;

  remove_duplicates(str,0);
  cout<<str<<endl;

  return 0;
}
