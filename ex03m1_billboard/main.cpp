#include <iostream>
#include <vector>

using namespace std;

vector<int> memo(100010, -1);

int recur(int index, vector<int> &v) {
    if (index >= v.size()) return 0;
    if (memo[index] != -1) return memo[index];

    int take = v[index] + recur(index + 2, v);
    int skip = recur(index + 1, v);

    return memo[index] = max(take, skip);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    cout << recur(0, v) << "\n";
    return 0;
}
