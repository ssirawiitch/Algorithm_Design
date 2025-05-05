#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> v(m);
    vector<int> s(m,0);
    for(int i = 0;i<m;i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    // trivial case
    for(int i = 0;i<n;i++){
        s[i] = v[i];
    }
    // next
    for(int i = n;i<m;i++){
        s[i] = s[i-n] + v[i];
    }
    double ans = 0;
    for(int i = 0;i<m;i++){
        ans += s[i];
    }
    ans = ans/m;
    cout << fixed << setprecision(3) << ans << endl;  // Output: 8.500
}
