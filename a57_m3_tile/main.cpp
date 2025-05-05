#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = 1e9; // ค่าที่ใช้แทนกรณีเป็นไปไม่ได้

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i]; // อ่านค่าความกว้างของกระเบื้องแต่ละแผ่น
    }

    vector<vector<int>> dp(N + 1, vector<int>(M + 1, INF)); // DP ตารางขนาด (N+1) x (M+1)
    dp[0][0] = 0; // ตั้งค่าเริ่มต้นให้ไม่มีค่าใช้จ่ายที่พื้นที่ 0

    for (int i = 0; i < N; i++) { // วนกระเบื้องแต่ละแผ่น
        for (int sum = 0; sum <= M; sum++) { // วนค่าพื้นที่ที่เป็นไปได้
            if (dp[i][sum] == INF) continue; // ถ้าค่า INF แสดงว่าเป็นไปไม่ได้ ข้ามไป

            for (int b = 1; b * b <= M; b++) { // ลองเปลี่ยนขนาด Bi ที่เป็นไปได้ (b * b คือพื้นที่ใหม่)
                int new_sum = sum + b * b;
                if (new_sum > M) continue; // ถ้าเกิน M ก็ข้ามไป

                int cost = (A[i] - b) * (A[i] - b); // คำนวณค่าใช้จ่ายของการเปลี่ยนขนาดกระเบื้อง

                // อัปเดต DP ถ้าพบค่าใช้จ่ายที่น้อยกว่า
                dp[i + 1][new_sum] = min(dp[i + 1][new_sum], dp[i][sum] + cost);
            }
        }
    }

    // ถ้า dp[N][M] ยังคงเป็น INF แสดงว่าไม่มีทางทำให้ได้พื้นที่ M
    cout << (dp[N][M] == INF ? -1 : dp[N][M]) << endl;

    return 0;
}
