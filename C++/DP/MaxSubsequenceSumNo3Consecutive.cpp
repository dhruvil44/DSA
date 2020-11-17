//Author:Dhruvil Patel(DP)

#include<bits/stdc++.h>

using namespace std;

//https://www.geeksforgeeks.org/maximum-subsequence-sum-such-that-no-three-are-consecutive/


int maxSubSeqSum(int a[], int n)
{

  int dp[n]={0};
  bool fromBack[n]={false};

  dp[0]=a[0];
  dp[1]=dp[0]+a[1];
  fromBack[1]=true;

  if(a[2]+dp[0]>a[1]+a[2])
  {
    dp[2]=a[2]+dp[0];
    fromBack[2]=false;
  }

  else{
    dp[2]=a[1]+a[2];
    fromBack[2]=true;
  }

  for(int i=3;i<n;i++)
  {
    int temp=INT_MIN;
    int t1=INT_MIN;
    int t2=INT_MIN;
    for(int j=0;j<i;j++)
    {
      if(j==i-1)
      {
        if(fromBack[j])
        {
          t1=a[i]+a[i-1]+dp[i-3];
        }

        else{
          t2=a[i]+dp[j];
        }

        if(temp<t1)
        {
          temp=t1;
          fromBack[i]=true;
        }

        if(temp<t2)
        {
          temp=t2;
          fromBack[i]=true;
        }
      }

      else if(temp<a[i]+dp[j])
      {
        temp=a[i]+dp[j];
      }
    }

    dp[i]=temp;
  }

  int m=INT_MIN;
  for(int i=0;i<n;i++)
  {
    m=max(m,dp[i]);
  }

  return m;

}

int main()
{

int a[]={100,1000,100,1000,1};

cout<<maxSubSeqSum(a,5);

  return 0;
}
