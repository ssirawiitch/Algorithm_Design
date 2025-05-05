#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000003;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> v(k);

    for (int i = 0; i < k; i++) {
        cin >> v[i];
    }

    // �� Dynamic Programming ᷹
    vector<int> dp(n + 1, 0);
    dp[0] = 1; // �� 1 �Ըշ������ remain == 0

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            if (i >= v[j]) {
                dp[i] = (dp[i] + dp[i - v[j]]) % MOD;
            }
        }
    }

    cout << dp[n] << "\n"; // �ͺ�ӹǹ�Ըշ������ sum == n
}
