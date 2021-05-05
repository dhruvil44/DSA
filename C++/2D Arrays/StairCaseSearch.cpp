//Author: Dhruvil Patel

#include<bits/stdc++.h>

using namespace std;

//Given a 2D Matrix which is sorted in rows as well as in columns. Find the cell(i,j) of a given element

struct cell{
  int i,j;
};

struct cell stairCaseSearch(int a[][4], int n , int m, int val) {

    int r=0,c=m-1;
    struct cell index;
    index.i=-1;
    index.j=-1;
    while (r<n && c<m) {
      if(val>a[r][c]) {
        r++;
      }
      else if(val<a[r][c]) {
        c--;
      }

      else{
        index.i = r;
        index.j = c;
        return index;
      }
    }

    return index;
}

int main() {


  int a[4][4];

  int n=4, m=4;
  int val=1;
  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      a[i][j]=val++;
    }
  }

  struct cell ans = stairCaseSearch(a,n,m,2);

  if(ans.i!=-1) {
    cout<<"Row = "<<ans.i<<endl;
    cout<<"Col = "<<ans.j<<endl;
  }
  else{
    cout<<"No element found"<<endl;
  }

  char a[4]={'h','e','l','l','o'};
  cout<<a<<endl;

  return 0;
}
