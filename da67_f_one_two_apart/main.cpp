#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    const int MOD = 100000007;
    vector<int> v(4);
    v[0] = 1;
    v[1] = 3;
    v[2] = 7;
    v[3] = 15;
    v.resize(n + 1);
    for (int i = 4; i <= n; i++) {
        v[i] = ((v[i - 1] * 2) + v[i - 3]) % MOD;
    }
    cout << v[n] << endl;
}
