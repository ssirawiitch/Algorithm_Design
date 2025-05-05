#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(int start, vector<vector<int>> &v, int k) {
    vector<int> visited(v.size(), 0);
    queue<int> q;
    int ans = 0;

    q.push(start);
    visited[start] = 1;

    while (!q.empty() && k > 0) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            int t = q.front();
            q.pop();
            for (auto &x : v[t]) {
                if (visited[x] == 0) {
                    visited[x] = 1;
                    q.push(x);
                    ans++;
                }
            }
        }
        k--;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, e, k, a, b;
    cin >> n >> e >> k;

    vector<vector<int>> v(n + 1);

    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    cout << bfs(0, v, k) << "\n";

    return 0;
}
