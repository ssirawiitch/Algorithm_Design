#include <bits/stdc++.h>

using namespace std;

const int MOD = 32717;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> R(n + 1, 0);
    vector<int> A(k + 1, 0);

    for (int i = 1; i <= k; ++i) {
        cin >> A[i];
        R[i] = A[i];

        cout << R[i] << " ";
    }

    for (int i = k + 1; i <= n; ++i) {
        int p;
        cin >> p;

        for (int j = 0; j < p; ++j) {
            int x;
            cin >> x;

            if (i - x <= 0) continue;

            R[i] += (R[i - x] % MOD);
        }
        R[i] %= MOD;

        cout << R[i] << " ";
    }
}
