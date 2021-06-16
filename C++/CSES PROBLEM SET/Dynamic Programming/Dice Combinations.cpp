

#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin>>n;
    const int mod = 1e9+7;
    vector<int> dp(n+1);

    dp[0]=0;
    for(int i=1;i<=min(n,6);i++) {
      dp[i]=1;
    }

    for(int i=2;i<=n;i++) {
        for(int j=1;j<=6;j++) {
            if(i>j) {
                dp[i] = (dp[i] + dp[i-j])%mod;
            }
        }
    }
    cout<<dp[n]%mod<<endl;
    return 0;
}
