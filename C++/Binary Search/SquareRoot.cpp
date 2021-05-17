//Author: Dhruvil Patel

#include<bits/stdc++.h>

using namespace std;

int squareRoot(int n) {

  int start=0;
  int end=n;

  int ans;

  while(start<=end) {
    int mid = (start+end)/2;

    if(mid*mid==n) {
      return mid;
    }

    if(mid*mid<=n) {
      ans=mid;
      start=mid+1;
    }

    else{
      end=mid-1;
    }
  }


  return ans;
}


float squareRootWithPrecision(int n, int p) {

  float ans = squareRoot(n);
  float inc = 0.1;
  while(p--) {

    while(ans*ans<=n) {
      ans+=inc;
    }

    if(ans*ans==n){
      return ans;
    }

    ans-=inc;
    inc/=10;

  }

  return ans;

}

int main() {

  int n;
  cin>>n;

  cout<<squareRoot(n)<<endl;

  cout<<squareRootWithPrecision(n,3)<<endl;


  return 0;
}
