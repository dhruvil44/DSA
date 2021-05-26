//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

//Given a set of integers where each number occurs thrice except one number. Find that unique number.

int main() {

  int a[] = {1,2,3,1,2,2,1,4,4,4};
  int n = sizeof(a)/sizeof(int);

  int sum[64]={0};

  for(int i=0;i<n;i++) {
      int num = a[i];
      int j=0;
      while(num>0) {
        int last_bit = (num&1);
        sum[j]+=last_bit;
        j++;
        num = (num>>1);
      }
  }


  int ans=0;
  int p=1;

  for(int i=0;i<64;i++) {
    sum[i]=sum[i]%3;

    ans+=p*sum[i];
    p=(p<<1);
  }

  cout<<ans<<endl;
  return 0;
}
