#include <iostream>
#include <vector>

using namespace std;

vector<int> matrix_multiply(const vector<int> &M, const vector<int> &N, int k) {
    vector<int> ans(4);
    ans[0] = ((M[0] * N[0]) + (M[1] * N[2])) % k;
    ans[1] = ((M[0] * N[1]) + (M[1] * N[3])) % k;
    ans[2] = ((M[2] * N[0]) + (M[3] * N[2])) % k;
    ans[3] = ((M[2] * N[1]) + (M[3] * N[3])) % k;
    return ans;
}

vector<int> matrix_power(const vector<int> &v, int n, int k) {
    if (n == 0) {
        return {1, 0, 0, 1}; // Identity matrix
    }
    vector<int> half_power = matrix_power(v, n / 2, k);
    vector<int> result = matrix_multiply(half_power, half_power, k);
    if (n % 2 == 1) {
        result = matrix_multiply(result, v, k);
    }
    return result;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(4);
    for (int i = 0; i < 4; i++) {
        cin >> v[i];
    }

    vector<int> ans = matrix_power(v, n, k);

    for (auto &x : ans) {
        cout << x << " ";
    }

    return 0;
}
