#include <iostream>
#include <vector>

using namespace std;

void dfs(int node,vector<vector<int>>& g,vector<int>& visited){

    visited[node] = 1;
    // all friend with node
    for(auto &x:g[node]){
        if(visited[x] == 0){
            dfs(x,g,visited);
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int v,e;
    cin >> v >> e;
    vector<vector<int>> g(v+1);
    vector<int> visited(v+1,0);
    for(int i = 0;i<e;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int ans = 0;
    // run in every vertex
    for(int i = 1;i<=v;i++){
        if(visited[i] == 0){
            dfs(i,g,visited);
            ans++;
        }
    }

    cout << ans;
}
