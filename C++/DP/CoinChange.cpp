//Author : Dhruvil Patel(DP)

#include<bits/stdc++.h>


using namespace std;



int minCoinChange(int coins[],int n,int amount)
{
  int i,j;

  int dp[amount+1];

  dp[0]=0;


  for(i=1;i<=amount;i++)
  {
    int temp=INT_MAX;

    for(j=0;j<n;j++)
    {
        if(i>=coins[j]){
              temp=min(temp,dp[i-coins[j]]);
          }
    }

    dp[i]=temp+1;
  }



return dp[amount];

}

int main()
{

  cout<<"Enter the number of coins";
  int n;
  cin>>n;

  cout<<"Enter the values";
  int coins[n];
  for(int i=0;i<n;i++)
  {
    cin>>coins[i];
  }

  cout<<"Enter the amount";
  int amount;
  cin>>amount;

  cout<<minCoinChange(coins,n,amount);

  return 0;
}
