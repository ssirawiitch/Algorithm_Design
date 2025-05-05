#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n), s(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        s[i] = v[i];
    }

    sort(s.begin(), s.end());

    vector<vector<int>> memo(n + 1, vector<int>(n + 1, 0));

    // DP
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (v[i - 1] == s[j - 1]) {
                memo[i][j] = memo[i - 1][j - 1] + 1;
            } else {
                memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
            }
        }
    }

    cout << memo[n][n];
    return 0;
}
