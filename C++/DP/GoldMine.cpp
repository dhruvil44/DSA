//Author:Dhruvil Patel(DP)

#include<bits/stdc++.h>

using namespace std;

//Given a matrix with weight of gold on each cell.Find out the maximum amount of gold you can pick if you can either go right,diagonally right up or diagonally right down
//if you are at i,j then you can go to i,j+1 OR i-1,j+1 OR i+1,j+1

int maxGold(int a[][4], int row, int col)
{
  int dp[row][col];

  for(int i=0;i<row;i++)
  {
    dp[i][0]=a[i][0];
  }

  for(int i=1;i<col;i++)
  {
    for(int j=0;j<row;j++)
    {
      if(j==0)
      {
        dp[j][i]=max(dp[j+1][i-1],dp[j][i-1])+a[j][i];
      }

      else if(j==row-1)
      {
        dp[j][i]=max(dp[j-1][i-1],dp[j][i-1])+a[j][i];
      }

      else{
        dp[j][i]=max(dp[j-1][i-1],max(dp[j][i-1],dp[j+1][i-1]))+a[j][i];
      }


    }
  }

  // for(int i=0;i<row;i++)
  // {
  //   for(int j=0;j<col;j++)
  //   {
  //     cout<<dp[i][j]<<" ";
  //   }
  //
  //   cout<<endl;
  // }

  int ans=INT_MIN;

  for(int i=0;i<row;i++)
  {
    ans=max(ans,dp[i][col-1]);
  }

  return ans;
}

int main()
{

  int a[4][4]={{10, 33, 13, 15},
               {22, 21, 04, 1},
               {5, 0, 2, 3},
               {0, 6, 14, 2}};

  cout<<maxGold(a,4,4);

  return 0;
}
