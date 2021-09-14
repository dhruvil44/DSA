//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

bool num_is_valid(int grid[][9], int i, int j, int number) {

  for(int k=0;k<9;k++) {
    //if the number is present in that row or column, it does no satisfy the constraints of the sudoku.
    if(grid[i][k]==number || grid[k][j]==number) {
      return false;
    }
  }

  //checking if the number is present in the smaller grid
  int startx = (i/3)*3;
  int starty = (j/3)*3;
  for(int k=startx;k<startx+3;k++) {
    for(int l=starty;l<starty+3;l++) {
      if(grid[k][l]==number) {
        return false;
      }
    }
  }

  return true;
}


//we go one by one element in a row and try to keep a number and check if rest part can be solved or not.
bool solve_sudoku(int grid[][9], int i, int j) {

  //if we have crossed the rows of the sudoku that means we have solved it.
  if(i==9) {
    // for(int k=0;k<9;k++) {
    //   for(int l=0;l<9;l++) {
    //     cout<<grid[k][l]<<" ";
    //   }
    //   cout<<endl;
    // }
    // cout<<endl<<endl;
    return true;
  }

  //if we have convered all the cells of the row then we move to the next row.
  if(j==9) {
    return solve_sudoku(grid,i+1,0);
  }

  if(grid[i][j]!=0) {
    return solve_sudoku(grid,i,j+1);
  }



    for(int num=1;num<=9;num++) {

      //if the num is valid and satisfies the constraints then we go further to solve the sudoku.
      if(num_is_valid(grid,i,j,num)) {

          grid[i][j] = num;
          bool further_sudoku = solve_sudoku(grid,i,j+1);

          if(further_sudoku) {
            return true;
          }

      }

    }

    //even if after keeping all numbers from 1-9 in the cell we are getting false..
    //from the further sudoku, we need to backtrack ie. we make this cell as 0 and return false to the parent.
    grid[i][j] = 0;
    return false;

}

int main() {

  int grid[9][9] = {   {3, 0, 6, 5, 0, 8, 4, 0, 0},
                       {5, 2, 0, 0, 0, 0, 0, 0, 0},
                       {0, 8, 7, 0, 0, 0, 0, 3, 1},
                       {0, 0, 3, 0, 1, 0, 0, 8, 0},
                       {9, 0, 0, 8, 6, 3, 0, 0, 5},
                       {0, 5, 0, 0, 9, 0, 6, 0, 0},
                       {1, 3, 0, 0, 0, 0, 2, 5, 0},
                       {0, 0, 0, 0, 0, 0, 0, 7, 4},
                       {0, 0, 5, 2, 0, 6, 3, 0, 0} };


    solve_sudoku(grid, 0, 0);

    for(int i=0;i<9;i++) {
      for(int j=0;j<9;j++) {
        cout<<grid[i][j]<<" ";
      }
      cout<<endl;
    }
  return 0;
}
