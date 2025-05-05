#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

const int INF = 1e9;
const int MAXN = 1000;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, C;
    cin >> R >> C;

    vector<vector<int>> grid(R, vector<int>(C));
    vector<pair<int, int>> starts;

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 2) {
                starts.emplace_back(i, j);
                grid[i][j] = 0;
            }
        }
    }

    int k = starts.size();
    vector<vector<vector<int>>> dist(k, vector<vector<int>>(R, vector<int>(C, INF)));

    for (int i = 0; i < k; ++i) {
        auto [sr, sc] = starts[i];
        queue<pair<int, int>> q;
        q.push({sr, sc});
        dist[i][sr][sc] = 0;

        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();

            for (int d = 0; d < 4; ++d) {
                int nr = r + dx[d];
                int nc = c + dy[d];

                if (nr >= 0 && nr < R && nc >= 0 && nc < C && grid[nr][nc] == 0 && dist[i][nr][nc] == INF) {
                    dist[i][nr][nc] = dist[i][r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
    }

    // ตรวจสอบว่าเป็น “ระยะห่างเท่ากัน” หรือไม่
    int result = 0;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (grid[i][j] != 0) continue;

            int min_d = INF, max_d = -INF;
            bool valid = true;
            for (int t = 0; t < k; ++t) {
                if (dist[t][i][j] == INF) {
                    valid = false;
                    break;
                }
                min_d = min(min_d, dist[t][i][j]);
                max_d = max(max_d, dist[t][i][j]);
            }

            if (valid && max_d - min_d <= 1) {
                result++;
            }
        }
    }

    cout << result << '\n';
    return 0;
}
