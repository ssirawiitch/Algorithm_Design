#include <iostream>
#include <vector>

using namespace std;

const int MOD = 100000007;

int main()
{
    long long n;
    cin >> n;
    vector<vector<long long>> dp(n + 1, vector<long long>(3, 0));
    // contain (00,01,10)

    dp[1][0] = 1; //00
    dp[1][1] = 1; //01
    dp[1][2] = 1; //10

    for(int i = 2;i<=n;i++){
        dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) % MOD;
        dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % MOD;
        dp[i][2] = (dp[i-1][0] + dp[i-1][1]) % MOD;
    }
    cout << (dp[n][0] + dp[n][1] + dp[n][2])%MOD;
}
