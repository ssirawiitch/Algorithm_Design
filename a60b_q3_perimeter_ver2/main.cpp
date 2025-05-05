#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, e, k;
    cin >> n >> e >> k;

    vector<vector<int>> graph(n + 1);  // ใช้ n+1 เพราะ a, b มีค่าตั้งแต่ 0 ถึง n

    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // BFS เพื่อหาค่าระยะทาง
    vector<int> dist(n + 1, -1);  // กำหนดค่าเริ่มต้นเป็น -1 แปลว่ายังไม่ถูกเยี่ยมชม
    queue<int> q;

    dist[0] = 0;  // ตำแหน่งฐาน (0) มีระยะทางเป็น 0
    q.push(0);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
            if (dist[v] == -1) {  // ถ้ายังไม่ถูกเยี่ยมชม
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    // นับจำนวนตำแหน่งที่มีระยะทางเท่ากับ k
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == k) {
            count++;
        }
    }

    cout << count << "\n";
    return 0;
}
