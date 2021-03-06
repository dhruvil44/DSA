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


  string lcs = "";
  //printing the longest common subsequece
  int row = s1.length();
  int col = s2.length();

  while(row>0 and col>0) {
    if(ans[row][col-1]==ans[row][col]) {
      col--;
    }

    else if(ans[row-1][col]==ans[row][col]) {
      row--;
    }

    else{
      lcs.push_back(s1[row-1]);
      row--;
      col--;
    }
  }

  reverse(lcs.begin(),lcs.end());
  cout<<lcs<<endl;


  return ans[s1.length()][s2.length()];

}


int main()
{
string s1 = "aggtab";
string s2 = "gxtxayb";

cout<<LCS(s1,s2);

  return 0;
}
