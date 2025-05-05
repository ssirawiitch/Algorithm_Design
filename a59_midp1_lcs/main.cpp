#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    string a, b;
    cin >> n >> m;
    cin >> a >> b;

    vector<vector<int>> memo(n + 1, vector<int>(m + 1));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cin >> memo[i][j];
        }
    }

    string ans = "";
    int ti = n, tj = m;

    while (ti > 0 && tj > 0) {
        if (a[ti - 1] == b[tj - 1]) {
            ans += a[ti - 1];
            ti--;
            tj--;
        } else if (memo[ti - 1][tj] > memo[ti][tj - 1]) {
            ti--;
        } else {
            tj--;
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans << endl;

    return 0;
}
