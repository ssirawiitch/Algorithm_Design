#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n, m;
int max_k = 1e-9;
int min_k = 1e9;
vector<int> K(8);
vector<vector<pair<int, int>>> g;
set<int> pathSum;

void dfs(int u, int sum, vector<bool>& visited ,int vst_node) {
    if(sum > max_k){return ;}
    if(sum + (n - vst_node)*max_k < min_k){return;}

    pathSum.insert(sum);
    for (auto [v, w] : g[u]) {
        if (!visited[v]) {
            visited[v] = true;
            dfs(v, sum + w, visited,vst_node+1);
            visited[v] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m;
    g.assign(n, {});

    for (int i = 0; i < 8; ++i) {
        cin >> K[i];
        max_k = max(max_k,K[i]);
        min_k = min(min_k,K[i]);
    }

    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        g[a].emplace_back(b, w);
        g[b].emplace_back(a, w);
    }

    // try all DFS
    for (int i = 0; i < n; ++i) {
        vector<bool> visited(n, false);
        visited[i] = true;
        dfs(i, 0, visited ,1);
    }

    for (int i = 0; i < 8; ++i) {
        if (pathSum.count(K[i])) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
