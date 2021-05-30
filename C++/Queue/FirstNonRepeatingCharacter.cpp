//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

int main() {

  //Take the input till a dot occurs
  int hashmap[27]={0};
  queue<char> q;
  
  char c;
  cin>>c;


  while(c!='.') {

      //Logic goes here


      //first of all insert the char in the queue and in the map
      q.push(c);
      hashmap[c-'a']++;

      while(!q.empty()) {
        if(hashmap[q.front()-'a']>1) {
          q.pop();
        }
        else{
          cout<<q.front()<<endl;
          break;
        }
      }

      if(q.empty()) {
        cout<<"-1\n";
      }

      cin>>c;
  }


  return 0;
}
