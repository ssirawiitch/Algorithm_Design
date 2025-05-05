#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,l,t,a,b;
    cin >> n >> l;
    vector<vector<int>> w(n+1,vector<int> (n+1,0));
    vector<vector<int>> v(n+1);

    w[1][2] = l;
    w[2][1] = l;
    v[1].push_back(2);
    v[2].push_back(1);

    for(int i = 1;i<=n-2;i++){
        cin >> t;
        vector<int> dist(n+1,1e9);

        for(int j = 0;j<t;j++){
            cin >> a >> b;
            w[i+2][a] = b;
            v[i+2].push_back(a);
            w[a][i+2] = b;
            v[a].push_back(i+2);
        }
        dist[1] = 0;

        // use Dijkstra
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,1});

        while(!pq.empty()){
            auto [u,o] = pq.top();
            pq.pop();
            for(auto &x:v[o]){
                if(dist[x] > u + w[o][x]){
                    dist[x] = u + w[o][x];
                    pq.push({dist[x],x});
                }
            }
        }
        cout << dist[2] << " ";
    }
}
