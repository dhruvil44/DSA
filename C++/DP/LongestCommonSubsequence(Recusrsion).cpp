//Author: Dhruvil Patel

#include<bits/stdc++.h>

using namespace std;


//Using Recursion Approach
int LCS(string s1,string s2,int l1,int l2)
{
  if(l1==s1.size()||l2==s2.size())
  {
    return 0;
  }

  if(s1[l1]==s2[l2])
  {
    return 1+LCS(s1,s2,l1+1,l2+1);
  }

  return max(LCS(s1,s2,l1+1,l2),LCS(s1,s2,l1,l2+1));

}

int main()
{

  string s1 = "AGGTAB";
  string s2 = "GXTXAYB";



  cout<<LCS(s1,s2,0,0);
  return 0;
}
