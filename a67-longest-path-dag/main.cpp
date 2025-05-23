#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    const int INF = 1e9;
    vector<vector<int>> dist(n+1,vector<int> (n+1,-INF));

    for(int i = 0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        dist[a][b] = c;
    }

    for(int k = 1;k<=n;k++){
        for(int i= 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(i!=j && dist[i][k]!=-INF && dist[k][j]!=-INF){
                    dist[i][j] = max(dist[i][j],dist[i][k] + dist[k][j]);
                }
            }
        }
    }


    int ans = 0;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(dist[i][j] != -INF && i!=j){
                ans = max(ans,dist[i][j]);
            }
        }
    }
    cout << ans;
    return 0;
}
