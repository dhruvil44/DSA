//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

// https://www.codechef.com/problems/TACHSTCK

int main() {


  long long int n,d;
  cin>>n>>d;

  long long int a[n];
  for(long long int i=0;i<n;i++) {
    cin>>a[i];
  }

  sort(a,a+n);
  long long int ans=0;
  for(long long int i=0;i<n-1;i++) {
      if(a[i+1]-a[i]<=d) {
        ans++;
        i++;
      }
  }

  cout<<ans<<endl;
  return 0;
}
