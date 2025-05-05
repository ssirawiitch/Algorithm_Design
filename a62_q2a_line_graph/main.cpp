#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

void dfs_cc(int s,int &cc_num,vector<vector<int>> &g,vector<int> &visited){
    visited[s] = cc_num;
    for(auto &x:g[s]){
        if(!visited[x]){
            dfs_cc(x,cc_num,g,visited);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    int v,e,a,b;
    cin >> v >> e;
    vector<vector<int>> g(v);
    vector<int> visited(v,0);
    vector<int> deg(v,0);
    for(int i = 0;i<e;i++){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        deg[a]++;deg[b]++;
    }

    int cc_num = 0;
    // connected component
    for(int i = 0;i<v;i++){
        if(!visited[i]){
            cc_num++;
            dfs_cc(i,cc_num,g,visited);
        }
    }
    // find element that has deg=1 and cc is i
    map<int,int> m;
    for(int i = 0;i<v;i++){
        if(!m.count(visited[i]) && deg[i] == 1){
            m[visited[i]] = i;
        }
    }

    vector<int> visited2(v,0);
    queue<int> q;
    int ans = cc_num;
    for(int i = 1;i<=cc_num;i++){

        // go through graph
        auto it = find(visited.begin(),visited.end(),i);
        int temp = it - visited.begin();
        int start = (m.size()==0)? temp:m[i];
        visited2[start] = 1;
        q.push(start);

        while(!q.empty()){
            int y = q.front();
            q.pop();
            if(g[y].size() > 2){ans--;break;}
            for(auto &x:g[y]){
                if(!visited2[x]){
                    q.push(x);
                    visited2[x] = 1;
                }
            }
        }
    }
    cout << ans;
    return 0;
}
