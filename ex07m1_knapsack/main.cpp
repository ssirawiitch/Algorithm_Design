#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

double maxValue = 0.0;
int n;
double w;

void recur(int start, double currentWeight, double currentValue,
           const vector<double>& wei, const vector<double>& val,
           const vector<double>& tail) {

    if (currentWeight > w) return;

    if (currentValue + tail[start] <= maxValue) return;

    if (start == n) {
        if (currentValue > maxValue) {
            maxValue = currentValue;
        }
        return;
    }

    if (currentWeight + wei[start] <= w) {
        recur(start + 1, currentWeight + wei[start], currentValue + val[start],
              wei, val, tail);
    }

    recur(start + 1, currentWeight, currentValue, wei, val, tail);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> w >> n;
    vector<double> val(n);
    vector<double> wei(n);

    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> wei[i];
    }

    vector<double> tail(n + 1, 0.0);
    for (int i = n - 1; i >= 0; i--) {
        tail[i] = tail[i + 1] + val[i];
    }

    recur(0, 0.0, 0.0, wei, val, tail);
    cout << fixed << setprecision(4) << maxValue << endl;

    return 0;
}
