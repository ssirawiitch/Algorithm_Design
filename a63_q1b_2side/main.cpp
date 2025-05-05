#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, w, k;
    cin >> n >> w >> k;

    vector<int> l(n + 1), r(n + 1);
    for (int i = 1; i <= n; ++i) cin >> l[i];
    for (int i = 1; i <= n; ++i) cin >> r[i];

    // DP arrays
    vector<int> dp_left(n + 1, 0), dp_right(n + 1, 0);

    // Initialize DP for the first kilometer
    dp_left[1] = l[1];
    dp_right[1] = r[1];

    // Sliding window to track the maximum values within the window
    vector<int> max_left(n + 1, 0), max_right(n + 1, 0);
    max_left[1] = dp_left[1];
    max_right[1] = dp_right[1];

    for (int i = 2; i <= n; ++i) {
        // Update dp_left[i] and dp_right[i]
        dp_left[i] = l[i] + max_right[max(0, i - w - 1)];
        dp_right[i] = r[i] + max_left[max(0, i - w - 1)];

        // Update max_left and max_right for the current position
        max_left[i] = max(max_left[i - 1], dp_left[i]);
        max_right[i] = max(max_right[i - 1], dp_right[i]);
    }

    // The answer is the maximum value between dp_left[n] and dp_right[n]
    int max_sum = max(max_left[n], max_right[n]);
    cout << max_sum << endl;

    return 0;
}
