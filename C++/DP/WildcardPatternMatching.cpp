//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

// Given a text 'str' and a wildcard pattern 'pattern',
// The wildcard pattern can include the characters ‘?’ and ‘ * ’.
// ‘?’ – matches any single character
// ‘*’ – Matches any sequence of characters (including the empty sequence)
// Find out if the given text matches the pattern.

//Ex:-
//str   =   abbac
//pattern = a?*c
//Output:- Yes
//because here a matches with a, ? will match with b, * will match with ba and c matches with c.


//str   =   abbac
//pattern = *c?
//Output:- No
//because there is no way this patter could anyhow match with this string.


bool is_matching(string pattern, string str) {


  bool dp[pattern.size()+1][str.size()+1];

  dp[0][0] = true;

  //init the row with false
  for(int i=1;i<=str.size();i++) {
    dp[0][i]=false;
  }


  //init the first col with false but if there is a * then it will depend upon earlier value.
  for(int i=1;i<=pattern.size();i++) {
    if(pattern[i-1]=='*') {
      dp[i][0]=dp[i-1];
    }
    else{
      dp[i][0] = false;
    }
  }


  for(int i=1;i<=pattern.size();i++) {
    for(int j=1;j<=str.size();j++) {

      if(pattern[i-1]=='*') {
        dp[i][j] = false;

        for(int k=0;k<=j;k++) {
          if(dp[i-1][k]==true) {
            dp[i][j] = true;
            break;
          }
        }

      }

      else if(pattern[i-1]=='?') {
        dp[i][j] = dp[i-1][j-1];
      }

      else{

        if(pattern[i-1]==str[j-1]) {
          dp[i][j] = dp[i-1][j-1];
        }
        else{
          dp[i][j] = false;
        }

      }


    }
  }

  return dp[pattern.size()][str.size()];

}

int main() {



  string str;
  string pattern;

  cin>>str>>pattern;

  cout<<(is_matching(pattern,str)?"Yes\n":"No\n");


  return 0;
}
