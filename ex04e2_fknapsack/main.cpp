#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
    double w; int n;
    cin >> w >> n;
    vector<double> val(n);
    vector<double> wei(n);
    vector<double> cos(n);
    priority_queue<tuple<double, double, double>> pq;

    for(int i = 0; i < n; i++) {
        cin >> val[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> wei[i];
    }
    for(int i = 0; i < n; i++) {
        cos[i] = static_cast<double>(val[i]) / wei[i];
    }
    for(int i = 0; i < n; i++) {
        pq.push({cos[i], val[i], wei[i]});
    }

    double ans = 0.0;
    while(!pq.empty() && w > 0) {
        auto [a, b, c] = pq.top();
        pq.pop();
        if(w >= c) {
            w -= c;
            ans += b;
        } else {
            ans += a * w;
            w = 0;
        }
    }
    cout << fixed << setprecision(4) << ans;
    return 0;
}
