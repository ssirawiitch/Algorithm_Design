#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> v;
vector<bool> visited;
vector<int> parent;
int cycle_start = -1, cycle_end = -1;

bool dfs_cd(int node, int par) {
    visited[node] = true;
    parent[node] = par;

    for (int neighbor : v[node]) {
        if (neighbor == par) continue;
        if (visited[neighbor]) {
            cycle_start = neighbor;
            cycle_end = node;
            return true;
        }
        if (dfs_cd(neighbor, node)) return true;
    }
    return false;
}

int find_cycle_size() {
    int size = 1;
    int node = cycle_end;

    while (node != cycle_start) {
        size++;
        node = parent[node];
    }
    return size;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, x, y;
    cin >> n;

    v.assign(n, vector<int>());
    visited.assign(n, false);
    parent.assign(n, -1);

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    for (int s = 0; s < n; s++) {
        if (!visited[s]) {
            if (dfs_cd(s, -1)) {
                cout << find_cycle_size() << "\n";
                return 0;
            }
        }
    }

    return 0;
}
