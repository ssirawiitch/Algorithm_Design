#include<bits/stdc++.h>
using namespace std;
int dp[5050][2];
int main(){
    int n,k,i,j,mod = 100000007;
    cin >> n >> k;
    dp[1][0] = dp[1][1] = 1;
    for(i=2;i<=n;i++){
        dp[i][0] = (dp[i-1][0] + dp[i-1][1])%mod;
        dp[i][1] = dp[max(1,i-k+1)][0];
    }
    cout << (dp[n][0]+dp[n][1])%mod;
}

