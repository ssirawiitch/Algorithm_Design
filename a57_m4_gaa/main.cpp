#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int v[100000];
int s[100001];

// Function to get the sum of a subsequence from index st to e
int getSum(int st, int e) {
    return s[e + 1] - s[st];
}

// Function to compute the maximum contiguous subsequence sum
int sequence(int start, int stop) {
    if (start == stop) {
        return v[start];
    }

    int m = (start + stop) / 2;

    // Recursively compute the maximum sum in the left and right halves
    int l = sequence(start, m);
    int r = sequence(m + 1, stop);

    // Compute the maximum sum that crosses the midpoint
    int max_left = v[m];
    int current_sum = v[m];
    for (int i = m - 1; i >= start; i--) {
        current_sum += v[i];
        max_left = max(max_left, current_sum);
    }

    int max_right = v[m + 1];
    current_sum = v[m + 1];
    for (int i = m + 2; i <= stop; i++) {
        current_sum += v[i];
        max_right = max(max_right, current_sum);
    }

    int cross_sum = max_left + max_right;

    // Return the maximum of the three sums
    return max(max(l, r), cross_sum);
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // Compute prefix sums
    s[0] = 0;
    for (int i = 0; i < n; i++) {
        s[i + 1] = s[i] + v[i];
    }

    // Compute the maximum non-circular subsequence sum
    int max_non_circular = sequence(0, n - 1);

    // Compute the total sum of the array
    int total_sum = s[n];

    // Compute the minimum subsequence sum (inverted Kadane's algorithm)
    int min_sum = v[0];
    int current_min = v[0];
    for (int i = 1; i < n; i++) {
        current_min = min(v[i], current_min + v[i]);
        min_sum = min(min_sum, current_min);
    }

    // Compute the maximum circular subsequence sum
    int max_circular = total_sum - min_sum;

    // If all elements are negative, the maximum sum is the largest single element
    if (max_circular == 0) {
        max_circular = *max_element(v, v + n);
    }

    // The final result is the maximum of the non-circular and circular sums
    cout << max(max_non_circular, max_circular) << endl;

    return 0;
}
