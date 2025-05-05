#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int get_Sum(const vector<int> &s, int start, int stop) {
    return s[stop] - s[start - 1];
}

int max_sum_within_length(int start, int mid, int stop, const vector<int>& s, int w) {
    int max_sum = INT_MIN;  // Initialize with the smallest possible value

    // Max sum for left part, considering subarrays of length <= w
    int left_sum = INT_MIN;
    for (int i = mid; i >= start; --i) {
        int current_sum = 0;
        for (int j = i; j <= mid && (j - i + 1) <= w; ++j) {
            current_sum += s[j] - (i > 0 ? s[i - 1] : 0);
            left_sum = max(left_sum, current_sum);
        }
    }

    // Max sum for right part, considering subarrays of length <= w
    int right_sum = INT_MIN;
    for (int i = mid + 1; i <= stop; ++i) {
        int current_sum = 0;
        for (int j = i; j <= stop && (j - i + 1) <= w; ++j) {
            current_sum += s[j] - s[j - 1];
            right_sum = max(right_sum, current_sum);
        }
    }

    // Consider the max sum combining the left and right parts
    max_sum = max(max_sum, left_sum + right_sum);

    return max_sum;
}


int recur(vector<int> &v, vector<int> &s, int start, int stop, int w) {
    if (start == stop) {
        return v[start];
    }

    int mid = (start + stop) / 2;

    int left_max = recur(v, s, start, mid, w);
    int right_max = recur(v, s, mid + 1, stop, w);

    int cross_max = max_sum_within_length(start, mid, stop, s, w);

    return max({left_max, right_max, cross_max});
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, w;
    cin >> n >> w;
    vector<int> v(n);
    vector<int> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    s[0] = v[0];
    for (int i = 1; i < n; ++i) {
        s[i] = v[i] + s[i - 1];
    }

    cout << recur(v, s, 0, n - 1, w) << endl;

    return 0;
}
