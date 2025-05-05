#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int MOVE[6][2][2] = {
    {{ 0, -1 }, { 0, 1 }},
    {{ -1, 0 }, { 1, 0 }},
    {{ -1, 0 }, { 0, 1 }},
    {{ 0, 1 }, { 1, 0 }},
    {{ 1, 0 }, { 0, -1 }},
    {{ 0, -1 }, { -1, 0 }},
};

bool dfs(pii cur, pii prev, vector<vector<int>> &grid, vector<vector<bool>> &is_passed, int& aux) {
    int r = grid.size();
    int c = grid[0].size();

    if (is_passed[cur.first][cur.second]) return true;

    int pos_val = grid[cur.first][cur.second];

    is_passed[cur.first][cur.second] = true;

    // Move here
    for (int i = 0; i < 2; ++i) {
        int next_r = cur.first + MOVE[pos_val][i][0];
        int next_c = cur.second + MOVE[pos_val][i][1];

        if (next_r < 0 || next_r >= r || next_c < 0 || next_c >= c) continue;

        if (next_r == prev.first && next_c == prev.second) continue;

        int next_val = grid[next_r][next_c];

        for (int j = 0; j < 2; ++j) {
            int prev_r = next_r + MOVE[next_val][j][0];
            int prev_c = next_c + MOVE[next_val][j][1];

            if (prev_r == cur.first && prev_c == cur.second) {
                bool found_cycle = dfs(make_pair(next_r, next_c), make_pair(cur.first, cur.second), grid, is_passed, aux);
                if (found_cycle) {
                    ++aux;
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    int r, c;
    cin >> r >> c;

    vector<vector<int>> grid(r, vector<int>(c, 0));
    vector<vector<bool>> is_passed(r, vector<bool>(c, false));

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> grid[i][j];

            --grid[i][j];
        }
    }

    int answer = 0;
    int loop_number = 0;

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (is_passed[i][j]) continue;

            int tmp_answer = 0;
            dfs(make_pair(i, j), make_pair(-1, -1), grid, is_passed, tmp_answer);

            if (tmp_answer) {
                answer = max(answer, tmp_answer);
                ++loop_number;
            }
        }
    }

    cout << loop_number << " " << answer;
}
