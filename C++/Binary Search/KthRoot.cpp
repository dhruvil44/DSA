//Author: Dhruvil Patel

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//You are given two integers n and k. Find the greatest integer x, such that, x^k <= n.

void solve() {

	long long int n;
	cin>>n;

	long long int k;
	cin>>k;

	long long int s=0;
	long long int e=n;
	long long int ans=LONG_LONG_MIN;
	while(s<=e) {
		long long int mid = (s+e)/2;

		if(pow(mid,k)==n) {
			cout<<mid<<endl;
			return;
		}

		if(n>pow(mid,k)) {
			ans=max(ans,mid);
			s=mid+1;
		}

		else{
			e=mid-1;
		}
	}
	cout<<ans<<endl;
}

int main() {

	int t;
	cin>>t;

	while(t--) {
		solve();
	}

	return 0;
}
