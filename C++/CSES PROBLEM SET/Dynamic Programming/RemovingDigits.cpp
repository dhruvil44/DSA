//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

int main() {

  int n;
  cin>>n;
  int ans=0;

  while(n>0) {

    int temp = n;
    int maxi = -1;
    while(temp>0) {
      int a = temp%10;

      maxi = max(a,maxi);

      temp/=10;
    }

      n=n-maxi;
      ans++;
  }

cout<<ans<<endl;
  return 0;
}
