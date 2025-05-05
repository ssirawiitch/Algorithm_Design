#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, d;
    cin >> n >> d;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    long long ans = 0;

    for (int i = 0; i < n; i++) {
        int m = v[i] + d;
        auto it = upper_bound(v.begin(), v.end(), m);
        ans += (it - (v.begin() + i) - 1);
    }

    cout << ans << '\n';
}
