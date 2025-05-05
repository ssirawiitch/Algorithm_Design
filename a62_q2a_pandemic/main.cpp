#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(queue<pair<int, int>>& q, int track, vector<vector<int>>& v) {
    int r = v.size(), c = v[0].size();
    int ans = q.size();
    int days = 0;

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    while (!q.empty() && days < track) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                // check in range
                if (nx >= 0 && nx < r && ny >= 0 && ny < c && v[nx][ny] == 0) {
                    v[nx][ny] = 1;
                    q.push({nx, ny});
                    ans++;
                }
            }
        }
        days++;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int r, c, t;
    cin >> r >> c >> t;

    vector<vector<int>> v(r, vector<int>(c));
    queue<pair<int, int>> q;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> v[i][j];
            if (v[i][j] == 1) {
                q.push({i, j});
            }
        }
    }

    cout << bfs(q, t, v) << "\n";
}
