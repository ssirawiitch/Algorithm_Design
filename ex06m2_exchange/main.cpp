#include <iostream>
#include <vector>

using namespace std;

bool bellman(vector<vector<double>> &g, vector<double> &dist, int start, int n) {
    dist[start] = 1.0;

    // Relaxation loop
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (dist[j] > 0 && dist[j] * g[j][k] > dist[k]) {
                    dist[k] = dist[j] * g[j][k];
                }
            }
        }
    }

    for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
            if (dist[j] > 0 && dist[j] * g[j][k] > dist[k]) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int k, n;
    cin >> k;

    for (int i = 0; i < k; i++) {
        cin >> n;
        vector<vector<double>> R(n, vector<double>(n));

        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cin >> R[j][k];
            }
        }

        vector<double> dist(n, 0);
        if (bellman(R, dist, 0, n)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
