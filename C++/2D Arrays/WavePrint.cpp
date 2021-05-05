//Author: Dhruvil Patel

#include<bits/stdc++.h>

using namespace std;

int main() {


  int a[3][4];

  for(int i=0;i<3;i++) {
    for(int j=0;j<4;j++) {
      a[i][j]=i;
    }
  }

  int row=0;
  for(int col=0;col<4;col++) {

    if(col&1) {
      row=2;
      while(row>=0) {
        cout<<a[row][col];
        row--;
      }
    } else{
      row=0;
      while(row<3) {
        cout<<a[row][col];
        row++;
      }
    }

    cout<<endl;

  }


  return 0;
}
