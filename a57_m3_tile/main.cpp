#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = 1e9; // ��ҷ����᷹�ó���������

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i]; // ��ҹ��Ҥ������ҧ�ͧ������ͧ������
    }

    vector<vector<int>> dp(N + 1, vector<int>(M + 1, INF)); // DP ���ҧ��Ҵ (N+1) x (M+1)
    dp[0][0] = 0; // ��駤����������������դ������·���鹷�� 0

    for (int i = 0; i < N; i++) { // ǹ������ͧ������
        for (int sum = 0; sum <= M; sum++) { // ǹ��Ҿ�鹷���������
            if (dp[i][sum] == INF) continue; // ��Ҥ�� INF �ʴ������������ �����

            for (int b = 1; b * b <= M; b++) { // �ͧ����¹��Ҵ Bi �������� (b * b ��;�鹷������)
                int new_sum = sum + b * b;
                if (new_sum > M) continue; // ����Թ M ������

                int cost = (A[i] - b) * (A[i] - b); // �ӹǳ�������¢ͧ�������¹��Ҵ������ͧ

                // �ѻവ DP ��Ҿ��������·����¡���
                dp[i + 1][new_sum] = min(dp[i + 1][new_sum], dp[i][sum] + cost);
            }
        }
    }

    // ��� dp[N][M] �ѧ���� INF �ʴ��������շҧ��������鹷�� M
    cout << (dp[N][M] == INF ? -1 : dp[N][M]) << endl;

    return 0;
}
