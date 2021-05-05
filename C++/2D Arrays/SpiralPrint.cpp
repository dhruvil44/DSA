//Author: Dhruvil Patel

#include<bits/stdc++.h>

using namespace std;

void spiralPrint(int a[][1000], int n, int m) {

  int startRow=0;
  int endRow=n-1;
  int startCol=0;
  int endCol=m-1;

  while(startRow<=endRow and startCol<=endCol) {
  //print first row from left to right
  for(int i=startCol;i<=endCol;i++) {
    cout<<a[startRow][i]<<" ";
  }
  startRow++;


  //print last col from top to bottom
  if(endCol>startCol) {
  for(int i=startRow;i<=endRow;i++) {
    cout<<a[i][endCol]<<" ";
  }
    endCol--;
  }


  //print last row from right to left
  if(endRow>startRow) {
  for(int i=endCol;i>=startCol;i--) {
    cout<<a[endRow][i]<<" ";
  }
    endRow--;
  }


  //print fist col from bottom to up
  for(int i=endRow;i>=startRow;i--) {
    cout<<a[i][startCol]<<" ";
  }

  startCol++;
}
}
int main() {


  int a[3][1000];

  int val=1;

  for(int i=0;i<3;i++) {
    for(int j=0;j<4;j++) {
      a[i][j]=val++;
    }
  }

  //Initial Matrix
  for(int i=0;i<3;i++){
    for(int j=0;j<4;j++) {
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }

  spiralPrint(a,3,4);

  return 0;
}
