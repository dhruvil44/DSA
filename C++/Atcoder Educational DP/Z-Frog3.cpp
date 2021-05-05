//Author: Dhruvil Patel(DP)

#include<bits/stdc++.h>

using namespace std;

#define MOD 1000000007;

long long minim(long long int a, long long int b)
{
  if(a<b)
  {
    return a;
  }

  return b;
}

long long int power(long long int a,long long int b)
{
  if(b==0)
  {
    return 1;
  }

  if(b==1)
  {
    return a;
  }

  if(b&1)
  {
    return power(a,b/2)*power(a,b/2)*a;
  }

  else{
    return power(a,b/2)*power(a,b/2);
  }
}

int main()
{

  long long int n,c;
  scanf("%lld%lld",&n,&c);

  long long int h[n+1];
  long long int dp[n+1];



  long long int i,j;

  for(i=0;i<n;i++)
  {
    scanf("%lld",&h[i]);
  }

  dp[0]=0;
  dp[1]=power(abs(h[0]-h[1]),2)+c;


  for(i=2;i<n;i++)
  {
    long long int temp=LONG_LONG_MAX;
    for(j=0;j<i;j++)
    {
        temp=minim(temp,power(h[i]-h[j],2)+c+dp[j]);
    }

    dp[i]=temp;
  }


  cout<<dp[n-1]<<endl;


  return 0;
}
