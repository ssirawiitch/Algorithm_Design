#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(vector<int> &v, int query) {
    int n = v.size();
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            int sum = v[i] + v[j];
            if (sum >= query) continue;
            int need = query - sum;

            auto it = lower_bound(v.begin() + j + 1, v.end(), need);

            if (it != v.end() && *it == need) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, q;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> q;
        cout << (check(v, q) ? "YES" : "NO") << endl;
    }
}
