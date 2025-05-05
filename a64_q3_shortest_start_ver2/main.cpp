#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void bellmanFord(int n, int v, vector<pair<int, pair<int, int>>> &edges, vector<int> &start_points) {
    vector<int> dist(n, INT_MAX);

    for (int s : start_points) {
        dist[s] = 0;
    }

    for (int i = 0; i < n - 1; i++) {
        for (auto edge : edges) {
            int u = edge.first, w = edge.second.second, to = edge.second.first;
            if (dist[u] != INT_MAX && dist[u] + w < dist[to]) {
                dist[to] = dist[u] + w;
            }
        }
    }

    cout << (dist[v] == INT_MAX ? -1 : dist[v]) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k, v;
    cin >> n >> m >> k >> v;

    vector<int> start_points(k);
    for (int i = 0; i < k; i++) {
        cin >> start_points[i];
    }

    vector<pair<int, pair<int, int>>> edges;

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edges.push_back({a, {b, w}});
    }

    bellmanFord(n, v, edges, start_points);
}
