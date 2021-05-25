//Author: Dhruvil Patel

#include<bits/stdc++.h>

using namespace std;

// https://www.spoj.com/problems/BALIFE/


int main() {

  int n;
  cin>>n;

  int a[n];
  int sum=0;
  for(int i=0;i<n;i++) {
    cin>>a[i];
    sum+=a[i];
  }

  if(sum%n!=0) {
    cout<<"-1\n";
  }

  else{
    int required_jobs;
    int current_jobs=0;
    int job_per_balancer=sum/n;

    int ans=INT_MIN;

    for(int i=0;i<n-1;i++) {
      current_jobs+=a[i];

      required_jobs = (i+1)*job_per_balancer;

      int differece = abs(current_jobs-required_jobs);

      ans=max(ans,differece);

    }

    cout<<ans<<endl;
  }



  return 0;
}
