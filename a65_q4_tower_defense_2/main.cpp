#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k, w, h;
    cin >> n >> m >> k >> w;

    int sum_mon = 0;
    vector<int> pos_mon(m);
    vector<int> health(n + 2, 0);

    for(int i = 0; i < m; i++){
        cin >> pos_mon[i];
    }

    for(int i = 0; i < m; i++){
        cin >> h;
        health[pos_mon[i]] += h;
        sum_mon += h;
    }

    for(int i = 1; i <= n && k > 0; i++){

        int L = max(1, i - w);
        int R = min(n, i + w);

        for(int j = L; j <= R; j++){
            if (health[j] > 0) {
                health[j]--;
                sum_mon--;
                k--;
                break;
            }
        }
    }

    cout << sum_mon << '\n';
}
