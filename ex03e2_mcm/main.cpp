#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n+1);
    vector<vector<int>> memo(n,vector<int> (n,INT_MAX));
    for(int i = 0;i<=n;i++){
        cin >> v[i];
    }

    // Trivial case
    for(int i=0;i<n;i++){
        memo[i][i] = 0;
    }

    for(int len = 2; len < n+1; len++) { // len = ขนาดของ chain
        for(int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;
            memo[i][j] = INT_MAX;
            for(int k = i; k < j; k++) {
                int cost = memo[i][k] + memo[k+1][j] + v[i] * v[k+1] * v[j+1];
                memo[i][j] = min(memo[i][j], cost);
            }
        }
    }
    cout << memo[0][n-1] ;
}
