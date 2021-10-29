//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/decode-ways/
*/

/*
A message containing letters from A-Z can be encoded into numbers using the following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"

Find all the strings possible by this kind of mapping

Input:- "123"
Output:- ABC, LC, AW
*/


void generate( string input, int idx, string ans, map<int,char>mp, bool double_pair ) {

  if(idx == input.size()) {
    cout<<ans<<endl;
    return;
  }

  //if the current element is 0 then we have to pair it with the previous element if it is less than 2 and greater than 1
  if(input[idx]=='0') {
    ans.pop_back();

    if(idx-1>=0 and input[idx-1]>='1' and input[idx-1]<='2') {
      char ch1 = input[idx-1];
      char ch2 = input[idx];
      string temp = "";
      temp += ch1;
      temp += ch2;

      int num = stoi(temp);

      ans += mp[num];
                                  //here we are pairing 0 with the input[idx-1] hence we pass true
      generate(input, idx+1, ans, mp, true);
    }
  }

  //if this current element is not '0'
  if(input[idx]!='0') {

    char ch = input[idx];
    int num = ch - '0';

    ans += mp[num];
                                // here this element is not paired with anyone hence we pass false.
    generate(input, idx+1, ans, mp, false);

  }

  //here double_pair denotes that whether we have paired the previous element with some one or not.
  //if we have paired the previous element with some one then, we cant pair the current element with the previous one.
  //For ex:- "123"
  //Lets say that 2 is paired with 1 and made 'L'.
  //Now 3 cant be paired with 2, instead 3 has to remain alone and make 'C'.


  //pairing this element with the previous element if the number formed is less than equal to 26
  if(double_pair == false and idx-1 >=0 and input[idx]<='6' and input[idx]>'0' and
                             input[idx-1]>='1' and input[idx-1]<='2') {
    ans.pop_back();
    ans.pop_back();

    char ch1 = input[idx-1];
    char ch2 = input[idx];
    string temp = "";
    temp += ch1;
    temp += ch2;

    int num = stoi(temp);

    ans += mp[num];
                          // here we are pairing this element with previous element that is input[idx-1], hence we pass true.
    generate(input, idx+1, ans, mp, true);
  }


}


int main() {

  map<int,char> mp;
  char ch = 'A';
  for(int i=1; i<=26; i++) {
    mp[i] = ch;
    ch++;
  }

  generate("10123",0,"",mp, false);

  cout<<endl;

  generate("123",0,"",mp,false);

  cout<<endl;

  generate("1212",0,"",mp,false);

  return 0;
}
