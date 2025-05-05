#include <iostream>
#include <vector>
#include <unordered_set>
#include <sstream>

using namespace std;

int n, m, room;
vector<vector<int>> g;
vector<int> color;
unordered_set<string> visited;

string getStateString(const vector<int>& state) {
    stringstream ss;
    for (int i = 1; i <= room; ++i) {
        ss << state[i];
    }
    return ss.str();
}

bool check_ans(const vector<int>& color) {
    for (int i = 1; i <= n; ++i) {
        if (color[i] != 2) return false;
    }
    for (int i = n + 1; i <= 2 * n; ++i) {
        if (color[i] != 1) return false;
    }
    return true;
}

vector<int> recur(int start, vector<int> color, vector<int> ans,int prev) {
    string state = getStateString(color);
    if (visited.count(state)) return {};
    visited.insert(state);

    if (check_ans(color)) return ans;

    if (ans.size() > 1000) return {};

    for (int x : g[start]) {
        if(x != prev){
            vector<int> next_color = color;
            swap(next_color[start], next_color[x]);
            vector<int> next_ans = ans;
            next_ans.push_back(x);

            vector<int> res = recur(x, next_color, next_ans,start);
            if (!res.empty()) return res;
        }
    }

    return {};
}

int main() {
    cin >> n >> m;
    room = 2 * n + 1;
    g.resize(room + 1);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    color.resize(room + 1, 0);
    for (int i = 1; i <= n; ++i) color[i] = 1;
    for (int i = n + 1; i <= 2 * n; ++i) color[i] = 2;
    color[room] = 0;

    vector<int> ans = recur(room, color, {},-1);

    if (!ans.empty()) {
        cout << ans.size() << "\n";
        for (int z : ans) cout << z << " ";
        cout << "\n";
    } else {
        cout << -1 << "\n";
    }

    return 0;
}
