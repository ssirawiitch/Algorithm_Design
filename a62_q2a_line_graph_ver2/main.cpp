#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

void dfs_cc(int s, int &cc_num, vector<vector<int>> &g, vector<int> &visited) {
    visited[s] = cc_num;
    for (auto &x : g[s]) {
        if (!visited[x]) {
            dfs_cc(x, cc_num, g, visited);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int v, e, a, b;
    cin >> v >> e;
    vector<vector<int>> g(v);
    vector<int> visited(v, 0);
    vector<int> deg(v, 0);

    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }

    int cc_num = 0;
    map<int, vector<int>> cc_nodes;  // บันทึก node ทั้งหมดในแต่ละ connected component

    // ค้นหา connected components และบันทึก node ที่อยู่ในแต่ละ component
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            cc_num++;
            dfs_cc(i, cc_num, g, visited);
        }
        cc_nodes[visited[i]].push_back(i);
    }

    vector<int> visited2(v, 0);
    queue<int> q;
    int ans = 0;

    // ตรวจสอบแต่ละ connected component ว่าเป็นกราฟเส้นตรงหรือไม่
    for (auto &comp : cc_nodes) {
        int comp_id = comp.first;
        vector<int> nodes = comp.second;

        int edge_count = 0;
        int max_deg = 0;
        int start_node = -1;

        // นับจำนวน edge และหาจุดเริ่มต้นที่ degree = 1
        for (int node : nodes) {
            edge_count += g[node].size();
            max_deg = max(max_deg, (int)g[node].size());
            if (deg[node] == 1) {
                start_node = node;
            }
        }
        edge_count /= 2;  // เพราะเป็น undirected graph

        // เงื่อนไขกราฟเส้นตรง: ต้องเป็น tree ที่มีโหนด degree ≤ 2 และ edge = node - 1
        if (edge_count == (int)nodes.size() - 1 && max_deg <= 2) {
            ans++;
        }
    }

    cout << ans << "\n";
    return 0;
}
