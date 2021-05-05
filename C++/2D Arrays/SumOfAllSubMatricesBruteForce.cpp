//Author:  Dhruvil Patel

#include<bits/stdc++.h>

using namespace std;


void bruteForce(int a[][2], int n, int m) {
  int sum=0;

  //Logic
  for(int topLeftx=0; topLeftx<n;topLeftx++) {
    for(int topLefty=0; topLefty<m;topLefty++) {

      for(int bottomRightx=topLeftx; bottomRightx<n; bottomRightx++) {
        for(int bottomRighty=topLefty; bottomRighty<m; bottomRighty++) {


          for(int i=topLeftx;i<=bottomRightx;i++){
            for(int j=topLefty; j<=bottomRighty; j++) {
              sum+=a[i][j];
            }
          }

        }
      }
    }
  }

  cout<<sum<<endl;

}


void prefixSumApproach(int a[][2], int n, int m) {


  //making prefix sum 2d array
  int prefix[n][m];

  //first row wise
  for(int i=0;i<m;i++) {
    for(int j=0;j<n;j++) {
      if(j==0) {
        prefix[j][i] = a[j][i];
      }
      else{
        prefix[j][i] = a[j][i] + prefix[j-1][i];
      }
    }
  }

  //then col wise
  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      if(j==0) {
        prefix[i][j]=prefix[i][j];
      }
      else{
        prefix[i][j] = prefix[i][j] + prefix[i][j-1];
      }
    }
  }


  int sum=0;
  for(int topLeftx=0; topLeftx<n; topLeftx++) {
    for(int topLefty=0; topLefty<m; topLefty++) {

      for(int bottomRightx=topLeftx; bottomRightx<n; bottomRightx++) {
        for(int bottomRighty=topLefty; bottomRighty<m; bottomRighty++) {

          sum+=prefix[bottomRightx][bottomRighty];

          if(topLeftx-1>=0) {
            sum-=prefix[topLeftx-1][bottomRighty];
          }

          if(topLefty-1>=0) {
            sum-=prefix[bottomRightx][topLefty-1];
          }

          if(topLeftx-1>=0 && topLefty-1>=0) {
            sum+=prefix[topLeftx-1][topLefty-1];
          }

        }
      }
    }
  }

    cout<<sum<<endl;
}

void mostOptimalApproach(int a[][2], int n, int m) {

  int sum=0;

  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {

      int topLeftCandidates = (i+1)*(j+1);
      int bottomRightCandidates = (n-i)*(m-j);

      sum=sum+a[i][j]*topLeftCandidates*bottomRightCandidates;
    }
  }
  cout<<sum<<endl;
}

int main() {


  int a[2][2];
  int n=2;
  int m=2;

  int val=1;
  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      a[i][j]=val++;
    }
  }


  mostOptimalApproach(a,2,2);

  prefixSumApproach(a,2,2);

  bruteForce(a,2,2);

  return 0;
}
