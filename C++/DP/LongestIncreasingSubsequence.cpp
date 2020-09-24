//Authior:Dhruvil Patel

#include<bits/stdc++.h>

using namespace std;


int LIS(int a[],int n)
{

  //table for memoisation
  //intializing all values to 1
  int dp[n];


  int i,j;

  for(i=0;i<n;i++)
  {
    dp[i]=1;
    for(j=i-1;j>=0;j--)
    {
      if(a[j]<=a[i])
      {
        dp[i]=max(dp[i],dp[j]+1);
      }
    }

  }

  int longestLength=INT_MIN;

  for(i=0;i<n;i++)
  {
    longestLength=max(longestLength,dp[i]);
  }

  return longestLength;

}

int main()
{
  int a[]={50,3,80,7,40,90};

  cout<<LIS(a,6);
}
