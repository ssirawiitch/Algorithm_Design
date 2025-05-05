#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M, K;
int dp[50][50][50][2];

int recur(int n, int m, int k, int l) {
    if (n == N) {
        return k == K ? 1 : 0;
    }

    if (dp[n][m][k][l] != -1) {
        return dp[n][m][k][l];
    }

    int result = 0;

    // Case 1: Add a black line (0)
    if (l == 0) {
        if (m + 1 <= M) {
            result += recur(n + 1, m + 1, k, 0);  // Same color
        } else {
            result += recur(n + 1, 1, k + 1, 0);  // Color change
        }
    } else {  // Last line was white (1)
        result += recur(n + 1, 1, k + 1, 0);
    }

    // Case 2: Add a white line (1)
    if (l == 1) {
        if (m + 1 <= M) {
            result += recur(n + 1, m + 1, k, 1);  // Same color
        } else {
            result += recur(n + 1, 1, k + 1, 1);  // Color change
        }
    } else {  // Last line was black (0)
        result += recur(n + 1, 1, k + 1, 1);
    }

    return dp[n][m][k][l] = result;
}

int main() {
    cin >> N >> M >> K;
    memset(dp, -1, sizeof(dp));

    cout << recur(1, 1, 0, 0) << endl;

    return 0;
}
