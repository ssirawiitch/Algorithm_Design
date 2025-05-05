#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dijkstra(int start,int fix,vector<vector<int>> &g,vector<vector<int>> &w,vector<vector<int>> &dist){

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[fix][start] = 0;
    pq.push({0,start});

    while(!pq.empty()){
        auto [t,node] = pq.top();
        pq.pop();

        for(auto &x:g[node]){
            if(dist[fix][x] > t + w[node][x]){
                dist[fix][x] = t + w[node][x];
                pq.push({dist[fix][x],x});
            }
        }
    }
}

int main()
{
    int n,m,a,b,c;
    cin >> n >> m;
    vector<vector<int>> w(n+1,vector<int> (n+1,0));
    vector<vector<int>> g(n+1);
    vector<vector<int>> dist(n+1,vector<int> (n+1,1e9));
    for(int i = 0;i<m;i++){
        cin >> a >> b >> c;
        w[a][b] = c;
        g[a].push_back(b);
    }

    for(int i =1;i<=n;i++){
        dijkstra(i,i,g,w,dist);
    }

    int ans = -1;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(dist[i][j] != 1e9 && i!=j){
                ans = max(ans,dist[i][j]);
            }
        }
    }
    cout << ans;
    return 0;
}
