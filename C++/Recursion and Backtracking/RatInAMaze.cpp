//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

/*
Given a matrix which is a maze. 0 in the matrix denotes that the path is blocked.
A rat starting from the top left corner wants to reach to the bottom right corner.
It can either move right or down.
Print all the possible paths.
*/

void find_all_paths(int grid[][10], int i, int j, int rows, int cols, int solution[][10]) {

  //mark the cell in our solution path
  solution[i][j] = 1;

  if(i==rows-1 and j==cols-1) {

    //print the solution path as we have reached the destination
    for(int k=0;k<rows;k++) {
      for(int l=0;l<cols;l++) {
        cout<<solution[k][l]<<" ";
      }
      cout<<endl;
    }

    cout<<endl<<endl;
    
    solution[i][j] = 0;
    return;
  }

  //go right if possible
  if(j+1<cols and grid[i][j+1]!=0) {
    find_all_paths(grid,i,j+1,rows,cols,solution);
  }

  //go down if possible
  if(i+1<rows and grid[i+1][j]!=0) {
    find_all_paths(grid,i+1,j,rows,cols,solution);
  }

  //after traversing in both the direction we bactrack ans make solution[i][j] = 0
  solution[i][j] = 0;


}

//find the total different number of ways to reach the destination using recursion
int no_of_ways(int grid[][10], int i, int j, int rows, int cols) {

  if(i==rows-1 and j==cols-1) {
    return 1;
  }

  int right_ways = 0, bottom_ways = 0;

  if(j+1<cols and grid[i][j+1]!=0) {
     right_ways = no_of_ways(grid,i,j+1,rows,cols);
  }

  if(i+1<rows and grid[i+1][j]!=0) {
      bottom_ways = no_of_ways(grid,i+1,j,rows,cols);
  }

  return right_ways + bottom_ways;

}


int main() {

  int grid[10][10] = { {1,1,0,1},
                   {1,1,1,0},
                   {0,1,1,1},
                   {1,1,1,1} };


  int rows = 4;
  int cols = 4;

  int solution[10][10] = {0};

  find_all_paths(grid,0,0,rows,cols,solution);
  cout<<endl<<endl;

  cout<<"The total number of ways = "<<no_of_ways(grid,0,0,rows,cols)<<endl;


  return 0;
}
