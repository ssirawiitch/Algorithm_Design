#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m,a,b,w;
    cin >> n >> m;
    vector<vector<int>> dist(n,vector<int> (n,1e9));

    for(int i = 0;i<m;i++){
        cin >> a >> b >> w;
        dist[a][b] = w;
        dist[b][a] = w;
    }

    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }

    for(int k = 0;k<n;k++){
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
    }

    int ans = -1;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(dist[i][j] != 1e9 && i != j){
                ans = max(ans,dist[i][j]);
            }
        }
    }
    cout << ans;
    return 0;
}
