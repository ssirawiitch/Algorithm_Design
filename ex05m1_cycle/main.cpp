#include <iostream>
#include <vector>

using namespace std;

bool dfs(int node, vector<vector<int>> &g, vector<int> &visited, int prev) {
    visited[node] = 1;
    for (auto &x : g[node]) {
        if (visited[x] == 0) {
            if (dfs(x, g, visited, node)) {
                return true;
            }
        } else if (x != prev) {
            return true;
        }
    }
    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, e;
        cin >> n >> e;
        vector<vector<int>> graph(n);
        vector<int> visited(n, 0);

        // Input graph
        for (int j = 0; j < e; j++) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        bool hasCycle = false;
        for (int j = 0; j < n; j++) {
            if (visited[j] == 0) {
                if (dfs(j, graph, visited, -1)) {
                    hasCycle = true;
                    break;
                }
            }
        }

        if (hasCycle) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
