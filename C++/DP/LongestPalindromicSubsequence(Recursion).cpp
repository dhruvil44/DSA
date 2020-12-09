//Author:Dhruvil Patel
#include<bits/stdc++.h>

using namespace std;

int longestPalindromicsubseq(string s,int i,int j)
{
  //i points to the first element of the string and j points to the last element of the string

  if(i>j)
  {
    return 0;
  }
  
  if(i==j)
  {
    return 1;
  }

  if(s[i]==s[j])
  {
    return longestPalindromicsubseq(s,i+1,j-1)+2;
  }

  else{
    return max(longestPalindromicsubseq(s,i+1,j),longestPalindromicsubseq(s,i,j-1));
  }

}

int main()
{

string s="BBABCBCAB";

cout<<longestPalindromicsubseq(s,0,s.size()-1);
  return 0;
}
