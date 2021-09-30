//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

/*
Take as input str, a string. Write a recursive function which
returns a new string in which all duplicate consecutive characters are separated by a ‘ * ’.
E.g. for “hello” return “hel*lo”. Print the value returned
*/

void format(char *str, int idx) {

  if(str[idx]=='\0') {
    return;
  }

  if(str[idx+1]!='\0' && str[idx]==str[idx+1]) {

    //step1:- tranfer all the chars from this index one step back
    int j = idx;
    while(str[j]!='\0') {
      j++;
    }

    while(j>idx) {
      str[j] = str[j-1];
      j--;
    }

    str[j+1] = '*';

    format(str,idx+2);
  }

  else{
    format(str,idx+1);
  }

}

int main() {


  char str[100000];
  cin>>str;

  format(str,0);
  cout<<str<<endl;


  return 0;
}
