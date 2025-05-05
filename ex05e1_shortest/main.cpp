#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int r, c;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int bfs(vector<vector<char>> &grid) {
    vector<vector<int>> visited(r, vector<int>(c, 0));
    queue<pair<int, int>> q;

    q.push({0, 0});
    visited[0][0] = 1;

    int steps = 0;

    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            auto [x, y] = q.front();
            q.pop();

            if (x == r - 1 && y == c - 1) return steps;

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];

                if (nx >= 0 && nx < r && ny >= 0 && ny < c && !visited[nx][ny] && grid[nx][ny] == '.') {
                    visited[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
        steps++;
    }

    return -1;
}

int main() {
    cin >> r >> c;
    vector<vector<char>> grid(r, vector<char>(c));

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> grid[i][j];

    cout << bfs(grid) << endl;
    return 0;
}
