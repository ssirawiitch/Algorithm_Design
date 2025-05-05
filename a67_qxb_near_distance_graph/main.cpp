#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m,p,k,q;
    cin >> n >> m >> p >> k;
    vector<vector<int>> w(n+1,vector<int> (n+1,0));
    vector<int> start(p);
    vector<vector<int>> dist(p,vector<int> (n+1,1e9));
    vector<vector<int>> g(n+1);

    for(int i = 0;i<p;i++){
        cin >> start[i];
    }
    for(int i = 0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        w[a][b] = c;
        w[b][a] = c;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int x = 0;x< p;x++){
        vector<bool> vst(n+1,false);
        queue<int> q;
        int ol = start[x];
        dist[x][ol]= 0;
        q.push(ol);
        vst[ol] = true;

        while(!q.empty()){
            int f = q.front();
            q.pop();
            for(auto &y:g[f]){
                if(!vst[y]){
                    dist[x][y] = min(dist[x][y],w[f][y] + dist[x][f]);
                    vst[y] = true;
                    q.push(y);
                }
            }
        }
    }

    int ans = 0;
    for(int i = 1;i<=n;i++){
        //auto it = find(start.begin(),start.end(),i);
        //if(it == start.end()){
            int max_e = -1e9;
            int min_e = 1e9;
            for(int j = 0;j<p;j++){
                if(dist[j][i] != 1e9){
                    max_e = max(max_e,dist[j][i]);
                    min_e = min(min_e,dist[j][i]);
                }
            }
            if(abs(max_e - min_e) <= k){
                ans++;
            }
        //}
    }
    cout << ans;
}
