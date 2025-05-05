#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> v(n+1,0);
    vector<int> w(n+1,0);
    vector<vector<int>> memo(n+1,vector<int> (m+1));

    for(int i = 1;i<n+1;i++){
        cin >> v[i];
    }
    for(int i = 1;i<n+1;i++){
        cin >> w[i];
    }
    for(int i = 0;i<=n;i++){
        for(int j = 0;j<=m;j++){
            cin >> memo[i][j];
        }
    }

    vector<int> ans;
    int t = m;
    for(int i = n;i>0;i--){
        if(memo[i][t] != memo[i-1][t]){
            ans.push_back(i);
            t -= w[i];
        }
    }
    cout << ans.size() << "\n";
    for(auto &x:ans){
        cout << x << " ";
    }
    return 0;
}
