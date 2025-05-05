#include<bits/stdc++.h>
using namespace std;
const int nax = 5e5 + 10;
int n, m, k;
int64_t a[nax];


int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        a[i] += a[i - 1] + k;
    }

    while (m -- ) {
        int l; int64_t cost;
        cin >> l >> cost; l += 1;
        /// a[r] - a[l - 1] <= cost
        /// a[r] <= cost + a[l + 1]
        int r = upper_bound(a + l, a + n + 1, a[l - 1] + cost) - a - 1;
        cout << a[r] - a[l - 1] - 1ll * k * (r - l + 1) << '\n';
    }

}
