#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> ans(n,0);
    for(int i = 0;i<n;i++){
        cin >> v[i];
    }

    // enforce to start at v[0]
    ans[0] = v[0];
    ans[1] = v[0] + v[1];
    ans[2] = max(v[0] + v[2] + v[1], v[0] + v[2]);


    for(int i = 3;i<=n-1;i++){
        ans[i] = max(max(ans[i-1],ans[i-2]),ans[i-3]) + v[i];
    }

    cout << ans[n-1];
}
