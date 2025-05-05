#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n,vector<int> (n,-1));
    vector<vector<int>> dp(n,vector<int> (n,-1)); // แต่ละช่องคือผลรวมที่มากที่สุดที่สิ้นสุดที่ช่องนั้น

    for(int i = 1;i<=n;i++){
        for(int j = 0;j<i;j++){
            cin >> v[i-1][j];
        }
    }
    // trivial case
    dp[0] = v[0];
    for(int i = 1;i<n;i++){
        dp[i][0] = dp[i-1][0] + v[i][0];
        dp[i][i] = dp[i-1][i-1] + v[i][i];
    }

    // dp
    for(int i = 2;i<n;i++){
        for(int j = 1;j<n-1;j++){
            dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]) + v[i][j];
        }
    }

    // find answer
    int ans = 1e-9;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<=i;j++){
            ans = max(ans,dp[i][j]);
        }
    }
    cout << ans;
    return 0;
}
