#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n, m;
int max_k = -1e9;
int min_k = 1e9;
vector<int> K(8);
vector<vector<pair<int, int>>> g;
set<pair<int,int>> memo;

bool dfs(int u, int sum, vector<bool>& visited, int target ,int vst_node) {
    if (sum == target) return true;
    if (sum > target) return false;
    if (sum + (n-vst_node)*max_k < target){return false;}
    if (sum + (n-vst_node)*min_k > target){return false;}

    for (auto [v, w] : g[u]) {
        if (!visited[v]) {
            visited[v] = true;
            if (dfs(v, sum + w, visited, target,vst_node+1)) return true;
            visited[v] = false;
        }
    }
    return false;
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

    for (int i = 0; i < 8; i++) {
        bool found = false;
        for (int j = 0; j < n; ++j) {
            vector<bool> visited(n, false);
            visited[j] = true;
            if (dfs(j, 0, visited, K[i],1)) {
                found = true;
                break;
            }
        }
        cout << (found ? "YES\n" : "NO\n");
    }

    return 0;
}
