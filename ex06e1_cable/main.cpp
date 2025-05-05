#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

vector<int> parent, ran;

void makeset(int n) {
    parent.resize(n);
    ran.resize(n, 0);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
}

int findset(int x) {
    if (parent[x] != x) {
        parent[x] = findset(parent[x]);
    }
    return parent[x];
}

void uni(int x, int y) {
    int rootX = findset(x);
    int rootY = findset(y);

    if (rootX != rootY) {
        if (ran[rootX] > ran[rootY]) {
            parent[rootY] = rootX;
        } else if (ran[rootX] < ran[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            ran[rootX]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, cost;
    cin >> n;

    vector<tuple<int, int, int>> edges;

    for (int i = 0; i < n - 1; i++) {
        for (int k = 0; k < n - i - 1; k++) {
            cin >> cost;
            edges.push_back({cost, i, i + k + 1});
        }
    }

    makeset(n);

    sort(edges.begin(), edges.end());

    int mst_cost = 0;
    int edges_used = 0;

    // Kruskal's Algorithm
    for (auto [cost, u, v] : edges) {
        if (findset(u) != findset(v)) {
            mst_cost += cost;
            uni(u, v);
            edges_used++;

            if (edges_used == n - 1) break;
        }
    }

    cout << mst_cost << '\n';
    return 0;
}
