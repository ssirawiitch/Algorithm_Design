#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void dfs(int start, int current, vector<vector<int>>& v, vector<vector<bool>>& visited) {
    visited[start][current] = true;
    for (auto& x : v[current]) {
        if (!visited[start][x]) {
            dfs(start, x, v, visited);
        }
    }
}

void dfs_cc(int i, vector<vector<int>>& new_v, map<int, vector<int>>& connect, int& cc_num, vector<bool>& visited2) {
    visited2[i] = true;
    connect[cc_num].push_back(i);
    for (auto& b : new_v[i]) {
        if (!visited2[b]) {
            dfs_cc(b, new_v, connect, cc_num, visited2);
        }
    }
}

int main() {
    int n, m, o;
    cin >> n;
    vector<vector<int>> v(n);
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    // Read input
    for (int i = 0; i < n; i++) {
        cin >> m;
        for (int j = 0; j < m; j++) {
            cin >> o;
            v[i].push_back(o);
        }
    }

    // Calculate reachability
    for (int i = 0; i < n; i++) {
        dfs(i, i, v, visited);
    }

    // Create new adjacency list with mutual connections
    vector<vector<int>> new_v(n);
    for (int i = 0; i < n; i++) {
        for (auto& y : v[i]) {
            if (visited[y][i] && visited[i][y]) {
                new_v[i].push_back(y);
            }
        }
    }

    // Find connected components
    int cc_num = 0;
    map<int, vector<int>> connect;
    vector<bool> visited2(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited2[i]) {
            cc_num++;
            dfs_cc(i, new_v, connect, cc_num, visited2);
        }
    }

    // Prepare and output results
    vector<int> sizes;
    for (auto& pair : connect) {
        sizes.push_back(pair.second.size());
    }
    sort(sizes.begin(), sizes.end());

    for (size_t i = 0; i < sizes.size(); i++) {
        if (i > 0) cout << " ";
        cout << sizes[i];
    }
    cout << endl;

    return 0;
}
