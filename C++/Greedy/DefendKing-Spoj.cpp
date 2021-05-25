//Author: Dhruvil Patel

#include<bits/stdc++.h>

using namespace std;

//https://www.spoj.com/problems/DEFKIN/cstart=20

void solve() {
  int width,height,n;
  cin>>width>>height>>n;

  int x[50000],y[50000];

  for(int i=0;i<n;i++) {
    cin>>x[i]>>y[i];
  }

  sort(x,x+n);
  sort(y,y+n);

  //Find maximum delta x and delta y
  int deltax = x[0]-1;
  int deltay = y[0]-1;

  for(int i=1;i<n;i++) {
    deltax = max(deltax,x[i]-x[i-1]-1);
    deltay = max(deltay,y[i]-y[i-1]-1);
  }

  deltax = max(deltax,width-x[n-1]);
  deltay = max(deltay,height-y[n-1]);

  cout<<deltax*deltay<<endl;

}

int main() {
    int t;
    cin>>t;

    while(t--) {
      solve();
    }
}
