//Author: Dhruvil Patel

#include<bits/stdc++.h>

using namespace std;

//https://www.geeksforgeeks.org/assembly-line-scheduling-dp-34/
//Diagram for assembly line is taken from this site.

int schedule(int a[][4],int t[][3], int startTimeFor1, int startTimeFor2, int endTimeFor1, int endTimeFor2)
{
  int dp[2][5];
  dp[0][0]=startTimeFor1+a[0][0];
  dp[1][0]=startTimeFor2+a[1][0];

  for(int i=1;i<4;i++)
  {
    dp[0][i]=min(dp[0][i-1]+a[0][i],dp[1][i-1]+t[1][i-1]+a[0][i]);
    dp[1][i]=min(dp[1][i-1]+a[1][i],dp[0][i-1]+t[0][i-1]+a[1][i]);
  }

  dp[0][4]=dp[0][3]+endTimeFor1;
  dp[1][4]=dp[1][3]+endTimeFor2;

  return min(dp[0][4],dp[1][4]);

}

int main()
{
  int a[][4]={{4,5,3,2},{2,10,1,4}};

  int t[][3]={{7,4,5},{9,2,8}};

  int startTimeFor1=10;
  int startTimeFor2=12;

  int endTimeFor1=18;
  int endTimeFor2=7;

  cout<<schedule(a,t,startTimeFor1,startTimeFor2,endTimeFor1,endTimeFor2);
}
