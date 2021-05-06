//Author: Dhruvil Patel

#include<bits/stdc++.h>

using namespace std;


void kadanesAlgo(int a[], int n) {


  int currSum=0;
  int ans=0;

  int l=0;
  int r=0;

  int begin=0;
  int end=0;

  for(int i=0;i<n;i++) {
    currSum+=a[i];

    if(currSum<0) {
      l=i+1;
      r=i+1;
      currSum=0;
    }

    else{
        r++;
    }

    if(currSum>ans) {
      ans=currSum;
      begin=l;
      end=r;
    }

  }

  cout<<"Max sum = "<<ans<<endl;

  cout<<"The subarray is"<<endl;
  for(int i=begin;i<end;i++) {
    cout<<a[i]<<" ";
  }

}

int main() {



  int a[] = {-4,1,3,-2,6,2,-8,-9,4};

  kadanesAlgo(a,9);


  return 0;
}
