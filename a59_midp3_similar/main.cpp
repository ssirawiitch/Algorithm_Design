#include <iostream>
#include <string>

using namespace std;

bool similar(int a_start, int a_stop, int b_start, int b_stop, const string& a, const string& b) {
    // Base case: if the substrings are identical, they are similar
    bool areEqual = true;
    for (int i = 0; i <= a_stop - a_start; ++i) {
        if (a[a_start + i] != b[b_start + i]) {
            areEqual = false;
            break;
        }
    }
    if (areEqual) {
        return true;
    }

    // If the length of the substrings is odd, they cannot be similar
    if ((a_stop - a_start + 1) % 2 != 0) {
        return false;
    }

    // Split the substrings into halves
    int a_mid = (a_start + a_stop) / 2;
    int b_mid = (b_start + b_stop) / 2;

    // Case 1: First half of a is similar to first half of b, and second half of a is similar to second half of b
    bool case1 = similar(a_start, a_mid, b_start, b_mid, a, b) &&
                 similar(a_mid + 1, a_stop, b_mid + 1, b_stop, a, b);

    // Case 2: First half of a is similar to second half of b, and second half of a is similar to first half of b
    bool case2 = similar(a_start, a_mid, b_mid + 1, b_stop, a, b) &&
                 similar(a_mid + 1, a_stop, b_start, b_mid, a, b);

    return case1 || case2;
}

int main() {
    string a, b;
    cin >> a >> b;

    // Check if the lengths are the same
    if (a.length() != b.length()) {
        cout << "NO" << endl;
        return 0;
    }

    // Check if the strings are similar
    if (similar(0, a.length() - 1, 0, b.length() - 1, a, b)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
