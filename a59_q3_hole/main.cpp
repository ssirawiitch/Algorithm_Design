#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <set>
#include <climits>

using namespace std;

const int MAX_N = 1000;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

set<pair<int, int>> sinkholes;

int bfs(int a, int b) {
    int ans = INT_MAX;
    vector<vector<int>> dist(MAX_N + 1, vector<int>(MAX_N + 1, INT_MAX));
    queue<tuple<int, int, int>> q;

    q.push({a, b, 0});
    dist[a][b] = 0;

    while (!q.empty()) {
        auto [x, y, fills] = q.front();
        q.pop();

        if (x == 1 || x == MAX_N || y == 1 || y == MAX_N) {
            ans = min(ans,fills);
            //return fills;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 1 || ny < 1 || nx > MAX_N || ny > MAX_N) continue;

            int new_fills = fills + (sinkholes.count({nx, ny}) ? 1 : 0);

            if (new_fills < dist[nx][ny]) {
                dist[nx][ny] = new_fills;
                q.push({nx, ny, new_fills});
            }
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, a, b;
    cin >> N >> a >> b;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        sinkholes.insert({x, y});
    }

    cout << bfs(a, b) << "\n";

    return 0;
}
