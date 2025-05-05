#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> virus(k);
    for (int i = 0; i < k; i++) {
        cin >> virus[i];
    }

    vector<int> c(n); // เวลาแฮก server i
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // Dijkstra multi-source
    vector<int> dist(n, 1e9);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;

    for (int i = 0; i < k; i++) {
        dist[virus[i]] = c[virus[i]];
        pq.push({dist[virus[i]], virus[i]});
    }

    while (!pq.empty()) {
        auto [t, u] = pq.top(); pq.pop();
        if (t > dist[u]) continue;

        for (int v : g[u]) {
            int new_time = t + c[v];
            if (new_time < dist[v]) {
                dist[v] = new_time;
                pq.push({new_time, v});
            }
        }
    }

    int ans = *max_element(dist.begin(), dist.end());
    cout << ans << '\n';

    return 0;
}
