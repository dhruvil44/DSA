//Author: Dhruvil Patel

#include<bits/stdc++.h>

using namespace std;

int main() {

  char s[100] = "Hello I am Dhruvil Patel";

  string str(s);

  cout<<s<<endl;
  char *ptr = strtok(s," ");
  cout<<ptr<<endl;

  while(ptr!=NULL) {
    ptr = strtok(NULL," ");
    cout<<ptr<<endl;
  }



  return 0;
}
