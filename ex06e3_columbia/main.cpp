#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

const int INF = 1e9;

int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};

void dijkstra(int R, int C, vector<vector<int>> &cost) {
    vector<vector<int>> dist(R, vector<int>(C, INF));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

    dist[0][0] = 0;
    pq.emplace(0, 0, 0); // {cost, row, col}

    while (!pq.empty()) {
        auto [d, r, c] = pq.top();
        pq.pop();

        if (d > dist[r][c]) continue;

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];

            if (nr >= 0 && nr < R && nc >= 0 && nc < C) {
                int new_cost = d + cost[nr][nc];

                if (new_cost < dist[nr][nc]) {
                    dist[nr][nc] = new_cost;
                    pq.emplace(new_cost, nr, nc);
                }
            }
        }
    }

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            cout << dist[r][c] << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int R, C;
    cin >> R >> C;

    vector<vector<int>> cost(R, vector<int>(C));
    for (int r = 0; r < R; r++)
        for (int c = 0; c < C; c++)
            cin >> cost[r][c];

    dijkstra(R, C, cost);
}
