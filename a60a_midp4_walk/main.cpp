#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> v(n+1,vector<int> (m+1,0));
    vector<vector<int>> memo(n+1,vector<int> (m+1,-1)); // memo[i][j] เก็บจำนวนแต้มมากสุดที่ช่องนั้น

    for(int i = 1;i<n+1;i++){
        for(int j = 1;j<m+1;j++){
            cin >> v[i][j];
        }
    }

    // trivial case
    memo[1][1] = v[1][1];
    for(int i = 2;i<=n;i++){
        memo[i][1] = memo[i-1][1] + v[i][1];
    }

    for(int i = 2;i<=m;i++){
        memo[1][i] = memo[1][i-1] + v[1][i];
    }

    // dp
    for(int i = 2;i<=n;i++){
        for(int j = 2;j<=m;j++){
            int tl = 2*v[i][j] + memo[i-1][j-1];
            int l = memo[i][j-1] + v[i][j];
            int t = memo[i-1][j] + v[i][j];
            memo[i][j] = max(max(tl,l),t);
        }
    }

    cout << memo[n][m];
    return 0;
}
