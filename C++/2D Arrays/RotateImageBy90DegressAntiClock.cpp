//Author: Dhruvil Patel

#include<bits/stdc++.h>

using namespace std;

//Rotating the Matrix anticliock wise by 90 degress we first reverse each row and then transpose the matrix
//In case if we rotate the matrix clockwise by 90 degress then we first take the transpose and then reverse each row
void rotateImage(int a[][4], int n, int m) {


  //Reverse each rows first
  for(int i=0;i<n;i++) {
    for(int j=0;j<m/2;j++) {
      swap(a[i][j],a[i][m-j-1]);
    }
  }


  //Take transpose of the matrix
  for(int i=0;i<n;i++) {
    for(int j=i+1;j<m;j++) {
      swap(a[i][j],a[j][i]);
    }
  }

  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }


}

int main() {


  int a[4][4];

  int val=1;

  for(int i=0;i<4;i++) {
    for(int j=0;j<4;j++) {
      a[i][j]=val++;
    }
  }

  rotateImage(a,4,4);

  return 0;
}
