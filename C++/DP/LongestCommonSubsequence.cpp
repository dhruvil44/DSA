//Author: Dhruvil Patel(DP)
#include<bits/stdc++.h>

using namespace std;



//Bottom Up Approach
int LCS(string s1,string s2)
{
  //table for storing the DP calculated values
  int ans[s1.length()+1][s2.length()+1];

  int i,j;

  for(i=0;i<=s1.length();i++)
  {
    for(j=0;j<=s2.length();j++)
    {
      if(i==0 || j==0)
      {
        ans[i][j]=0;
        continue;
      }

      if(s1[i-1]==s2[j-1])
      {
        ans[i][j]=ans[i-1][j-1]+1;
      }
      else{
        ans[i][j]=max(ans[i][j-1],ans[i-1][j]);
      }
    }
  }


  return ans[s1.length()][s2.length()];

}


int main()
{
string s1 = "abcdabcdab";
string s2 = "x";

cout<<LCS(s1,s2);

  return 0;
}
