#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, a, b, c;
    cin >> n >> m;
    vector<vector<int>> w(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, 1e9));

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        w[a][b] = c;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) dist[i][j] = 0;
            else if (w[i][j] != 0) dist[i][j] = w[i][j];
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] < 1e9 && dist[k][j] < 1e9)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int ans = -1e9;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] < 1e9) {
                ans = max(ans, dist[i][j]);
            }
        }
    }

    cout << ans;
    return 0;
}
