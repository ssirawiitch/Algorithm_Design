#include <iostream>
#include <vector>

using namespace std;

int n, e;
vector<vector<int>> adj;
vector<int> color;

bool is_valid(int node, int c) {
    for (int neighbor = 0; neighbor < n; ++neighbor) {
        if (adj[node][neighbor] && color[neighbor] == c) {
            return false;  // เพื่อนบ้านมีสีเดียวกัน
        }
    }
    return true;
}

bool color_graph(int node, int max_color) {
    if (node == n) return true;  // ระบายครบทุก node แล้ว

    for (int c = 1; c <= max_color; ++c) {
        if (is_valid(node, c)) {
            color[node] = c;
            if (color_graph(node + 1, max_color)) return true;
            color[node] = 0;  // backtrack
        }
    }

    return false;
}

int main() {
    cin >> n >> e;
    adj.assign(n, vector<int>(n, 0));
    color.assign(n, 0);

    for (int i = 0; i < e; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a][b] = adj[b][a] = 1;
    }

    for (int k = 1; k <= n; ++k) {
        if (color_graph(0, k)) {
            cout << k << "\n";
            break;
        }
    }

    return 0;
}
