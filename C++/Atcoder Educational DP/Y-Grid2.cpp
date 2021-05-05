//Author: Dhruvil Patel

#include<bits/stdc++.h>

using namespace std;


int main() {

   int MOD = 1000000007;
   int h,w,n;
  scanf("%d%d%d",&h,&w,&n);

   int grid[h][w];

  for(int i=0;i<h;i++) {
    for(int j=0;j<w;j++) {
      grid[i][j]=0;
    }
  }

  for(int i=0;i<n;i++) {
    int x,y;
    scanf("%d%d",&x,&y);
    x--;
    y--;
    //this means that at this cell there is a wall
    grid[x][y]=1;
  }

   int dp[h][w];
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++) {
      dp[i][j]=0;
    }
  }

  for(int i=0;i<w;i++) {
    if(grid[0][i]==1){
      break;
    }
    else{
      dp[0][i]=1;
    }
  }

  for(int i=0;i<h;i++) {
    if(grid[i][0]==1){
      break;
    }
    else{
      dp[i][0]=1;
    }
  }

  for(int i=1;i<h;i++) {
    for(int j=1;j<w;j++) {
      if(grid[i][j]!=1) {
        dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
      }
    }
  }

  cout<<dp[h-1][w-1];

  return 0;
}
