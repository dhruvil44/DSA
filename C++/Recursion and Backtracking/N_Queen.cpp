//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

/*
Given a N*N chess board. Place N Queens such that no Queen is killing any other queen.
*/

bool is_valid(int grid[][4], int row, int col, int n) {


  //check in the column
  for(int i=0;i<n;i++) {
    if(i!=row) {
      if(grid[i][col]==1) {
        return false;
      }
    }
  }

  //check diagonal wise from left to right
  int i = row-1;
  int j = col-1;
  while(i>=0 and j>=0) {
    if(grid[i][j]==1) {
      return false;
    }
    i--;
    j--;
  }

  //check other diagonal
  i = row - 1;
  j = col + 1;
  while(i>=0 and j<n) {
    if(grid[i][j]==1) {
      return false;
    }
    i--;
    j++;
  }

  return true;
}


bool solve_queeen(int grid[][4], int row, int n) {

  if(row==n) {

    for(int i=0;i<4;i++) {
      for(int j=0;j<4;j++) {
        if(grid[i][j]==1) {
          cout<<" Q ";
        }
        else{
          cout<<" . ";
        }
      }

      cout<<endl;
    }

    cout<<endl<<endl;

    // return true;

    //here we are returning true from the base case ..
    //but if we want all the possible n-queen solutions what we do is,
    //we simply return false from the base case..that means the recursion wont stop at the point if it got true.
    return false;
  }


  for(int col=0;col<n;col++) {

    if(is_valid(grid,row,col,n)) {
      grid[row][col] = 1;

      bool further_solve_queen = solve_queeen(grid,row+1,n);

      if(further_solve_queen) {
        return true;
      }
      else{
        grid[row][col] = 0;
      }
    }

  }

  return false;


}

int main() {

  int n = 4;
  int grid[4][4] = {0};

  solve_queeen(grid,0,n);

  // for(int i=0;i<4;i++) {
  //   for(int j=0;j<4;j++) {
  //     if(grid[i][j]==1) {
  //       cout<<" Q ";
  //     }
  //     else{
  //       cout<<" . ";
  //     }
  //   }
  //   cout<<endl;
  // }

  return 0;
}
