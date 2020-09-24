//Author: Dhruvil Patel

#include<bits/stdc++.h>

using namespace std;

int LCS(string s1,string s2,int l1,int l2)
{
  if(l1==s1.size()||l2==s2.size())
  {
    return 0;
  }

  int currCount;


  if(s1[l1]==s2[l2])
  {
    int i,j;
    i=l1+1;
    j=l2+1;
    currCount=1;
    while(i<s1.size() && j<s2.size())
    {
      if(s1[i]==s2[j])
      {
        i++;
        j++;
        currCount++;
      }
      else{
        break;
      }
    }
  }


    int currCount2=LCS(s1,s2,l1+1,l2);
    int currCount3=LCS(s1,s2,l1,l2+1);


  return max(currCount,max(currCount2,currCount3));


}

int main() {

  string s1="abcdxyz";
  string s2="xyzabcd";

  cout<<LCS(s1,s2,0,0);

  return 0;
}
