#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void floyd(vector<vector<int>> &dist, int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k, v, o;
    cin >> n >> m >> k >> v;

    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

    for (int i = 0; i < n; ++i) dist[i][i] = 0; // trivial case

    vector<int> start_points(k);
    for (int i = 0; i < k; i++) {
        cin >> start_points[i];
    }

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        dist[a][b] = w;
    }

    floyd(dist, n);

    int ans = INT_MAX;
    for (int s : start_points) {
        ans = min(ans, dist[s][v]);
    }

    cout << ans << "\n";
}
