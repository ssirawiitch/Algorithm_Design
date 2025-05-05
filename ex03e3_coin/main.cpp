#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> v(n+1,0);
    vector<vector<int>> memo(n+1,vector<int> (m+1,INT_MAX));
    for(int i = 1;i<=n;i++){
        cin >> v[i];
    }

    for (int i = 0; i <= n; i++) {
        memo[i][0] = 0;
    }

    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(v[i] > j){
                memo[i][j] = memo[i-1][j];
            }else{
                if (memo[i][j - v[i]] != INT_MAX) {
                    memo[i][j] = min(memo[i][j - v[i]] + 1, memo[i - 1][j]);
                } else {
                    memo[i][j] = memo[i - 1][j];
                }
            }
        }
    }

    cout << memo[n][m];
    return 0;
}
