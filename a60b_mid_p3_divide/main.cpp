#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1997;

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> v(n + 1, vector<int>(k + 1, 0));

    // Base cases
    for (int i = 0; i <= n; i++) {
        v[i][0] = 0;
        if (i >= 1) v[i][1] = 1;
        if (i <= k) v[i][i] = 1;
    }

    // DP computation
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= k; j++) {
            if (i >= j) {
                v[i][j] = (j * v[i - 1][j] + v[i - 1][j - 1]) % MOD;
            }
        }
    }

    cout << v[n][k] % MOD;
    return 0;
}
