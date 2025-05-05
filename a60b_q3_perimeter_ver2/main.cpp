#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, e, k;
    cin >> n >> e >> k;

    vector<vector<int>> graph(n + 1);  // �� n+1 ���� a, b �դ�ҵ���� 0 �֧ n

    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // BFS �����Ҥ�����зҧ
    vector<int> dist(n + 1, -1);  // ��˹������������� -1 ������ѧ���١��������
    queue<int> q;

    dist[0] = 0;  // ���˹觰ҹ (0) �����зҧ�� 0
    q.push(0);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
            if (dist[v] == -1) {  // ����ѧ���١��������
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    // �Ѻ�ӹǹ���˹觷�������зҧ��ҡѺ k
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == k) {
            count++;
        }
    }

    cout << count << "\n";
    return 0;
}
