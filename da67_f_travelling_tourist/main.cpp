#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> check;
int ans = 1e9;
void dijk(int start,vector<int> &dist,vector<vector<int>> &cost,vector<vector<int>> &g){

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,start});

    while(!pq.empty()){
        auto [t,node] = pq.top();
        pq.pop();

        for(auto &x:g[node]){
            if(dist[x] > t + cost[node][x]){
                dist[x] = t + cost[node][x];
                pq.push({dist[x],x});
            }
        }
    }

    // find answer
    int sum = 0;
    for(auto &y:check){
        sum += (dist[y]);
    }
    ans = min(ans,sum);
}

int main()
{
    int n,m,k,a,b,c,o;
    cin >> n >> m >> k;
    vector<vector<int>> cost(n+1,vector<int> (n+1));
    vector<vector<int>> g(n+1);
    for(int i = 0;i<k;i++){
        cin >> o;
        check.push_back(o);
    }
    for(int i = 0;i<m;i++){
        cin >> a >> b >> c;
        cost[a][b] = c;
        cost[b][a] = c;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // find start node
    vector<int> dist(n+1,1e9);
    vector<int> te(n+1,1e9);
    for(int i = 1;i<=n;i++){
        dist[i] = 0;
        dijk(i,dist,cost,g);
        dist = te;
    }
    cout << ans;
    return 0;
}
