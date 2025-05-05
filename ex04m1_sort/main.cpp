#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    // Step 1: Count how many 1s, 2s, 3s
    int c1 = 0, c2 = 0, c3 = 0;
    for (int x : a) {
        if (x == 1) ++c1;
        else if (x == 2) ++c2;
        else ++c3;
    }

    // Step 2: Build 3x3 confusion matrix
    // cnt[i][j] = number of j's in region i
    int cnt[4][4] = {}; // 1-based indexing

    for (int i = 0; i < c1; ++i) cnt[1][a[i]]++;
    for (int i = c1; i < c1 + c2; ++i) cnt[2][a[i]]++;
    for (int i = c1 + c2; i < n; ++i) cnt[3][a[i]]++;

    // Step 3: Greedy swap
    int swap_count = 0;

    // Direct swaps
    int s12 = min(cnt[1][2], cnt[2][1]);
    swap_count += s12;
    cnt[1][2] -= s12; cnt[2][1] -= s12;

    int s13 = min(cnt[1][3], cnt[3][1]);
    swap_count += s13;
    cnt[1][3] -= s13; cnt[3][1] -= s13;

    int s23 = min(cnt[2][3], cnt[3][2]);
    swap_count += s23;
    cnt[2][3] -= s23; cnt[3][2] -= s23;

    // Remaining mismatches are cycles (need 2 swaps per cycle)
    int leftover = cnt[1][2] + cnt[1][3]; // or cnt[2][1]+cnt[2][3], etc
    swap_count += leftover * 2;

    cout << swap_count << endl;

}
