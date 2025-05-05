#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1000003;

int recur(vector<int> &v, int remain, int index, vector<vector<int>> &memo) {
    if (remain == 0) return 1;
    if (index < 0 || remain < 0) return 0;

    if (memo[index][remain] != -1) return memo[index][remain];

    int c = 0, nc = 0;
    if (remain >= v[index]) {
        c = recur(v, remain - v[index], index, memo);
    }

    nc = recur(v, remain, index - 1, memo);

    return memo[index][remain] = (c + nc) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> v(k);

    for (int i = 0; i < k; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    vector<vector<int>> memo(k, vector<int>(n + 1, -1));

    cout << recur(v, n, k - 1, memo) << "\n";
}
