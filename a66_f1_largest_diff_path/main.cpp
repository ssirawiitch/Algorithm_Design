#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    vector<vector<int>> adj(n);
    vector<int> in_degree(n, 0);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        in_degree[v]++;
    }

    // Topological sort using Kahn's algorithm
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topo_order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo_order.push_back(u);
        for (int v : adj[u]) {
            in_degree[v]--;
            if (in_degree[v] == 0) {
                q.push(v);
            }
        }
    }

    vector<int> min_val(c.begin(), c.end());
    vector<int> max_diff(n, 0);

    // Process nodes in topological order
    for (int u : topo_order) {
        for (int v : adj[u]) {
            if (min_val[v] > min_val[u]) {
                min_val[v] = min_val[u];
            }
            if (max_diff[v] < c[v] - min_val[v]) {
                max_diff[v] = c[v] - min_val[v];
            }
        }
    }

    // Find the maximum difference
    int result = *max_element(max_diff.begin(), max_diff.end());
    cout << result << endl;

    return 0;
}
