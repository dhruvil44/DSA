//Author: Dhruvil Patel

#include<bits/stdc++.h>

using namespace std;

bool isSafe(int board[][8], int i, int j, int n)
{
  //checking for the column
  for(int row=0;row<i;row++)
  {
    if(board[row][j]==1)
    {
      return false;
    }
  }


  //checking for the left diagonal
  int x=i;
  int y=j;

  while(x>=0 && y>=0)
  {
    if(board[x][y]==1)
    {
      return false;
    }
    x--;
    y--;
  }

  //checking for right diagonal
  x=i;
  y=j;

  while(x>=0 && y<n)
  {
    if(board[x][y]==1)
    {
      return false;
    }
    x--;
    y++;
  }

  return true;
}

bool solveQueen(int board[][8], int i, int n)
{
  //Base Case
  if(i==n)
  {
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        if(board[i][j]==1)
        {
          cout<<"Q ";
        }
        else{
          cout<<"_ ";
        }
      }

      cout<<endl;
    }

    //return true if u want to stop at first solution
    return true;

    //return false if u want to get all possible solutions
    //return false;
  }

  //Checking For all columns
  for(int j=0;j<n;j++)
  {
    if(isSafe(board, i, j, n))
    {
      board[i][j]=1;

      if(solveQueen(board, i+1, n))
      {
        return true;
      }
    }

    //Else mark this cell as 0
    board[i][j]=0;
  }

  return false;
}

int main()
{

  int n=8;
  int board[8][8]={0};

  solveQueen(board,0,n);

  return 0;
}
