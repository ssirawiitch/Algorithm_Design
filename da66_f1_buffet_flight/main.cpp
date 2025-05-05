#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,a,b;
    cin >> n >> m;
    vector<int> co(n);
    vector<int> ci(n);
    vector<vector<int>> g(n);
    vector<vector<int>> w(n,vector<int> (n,0));

    for(int i = 0;i<n;i++){
        cin >> ci[i];
    }
    for(int i = 0;i<n;i++){
        cin >> co[i];
    }
    for(int i = 0;i<m;i++){
        cin >> a >> b;
        g[a].push_back(b);
        int out = co[a];
        int in = ci[b];
        w[a][b] = in+out;
    }

    // Dijkstra
    vector<int> dist(n,1e9);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0});
    dist[0] = 0;

    while(!pq.empty()){
        auto [f,l] = pq.top();
        pq.pop();

        for(auto &x:g[l]){
            if(dist[x] > f + w[l][x]){
                dist[x] = f + w[l][x];
                pq.push({dist[x],x});
            }
        }
    }

    for(auto &y:dist){
        if(y == 1e9){
            cout << -1 << " ";
        }else{
            cout << y << " ";
        }
    }
}
