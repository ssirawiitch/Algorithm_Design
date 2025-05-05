#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int n;

int bfs(int node,int k,vector<vector<int>> &v){

    queue<int> q;
    vector<int> visited(n,0);
    int ans = 1;
    int tr = 0;
    q.push(node);
    visited[node] = 1;

    while(!q.empty() && tr<k){
        int sz = q.size();
        for(int i = 0;i<sz;i++){
            int f = q.front();
            q.pop();

            for(auto &x:v[f]){
                if(!visited[x]){
                    q.push(x);
                    visited[x] = 1;
                    ans++;
                }
            }
        }tr++;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int e,k,a,b;
    cin >> n >> e >> k;
    vector<vector<int>> v(n);
    for(int i = 0;i<e;i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int ans = INT_MIN;
    for(int i = 0;i<n;i++){
        ans = max(ans,bfs(i,k,v));
    }

    cout << ans;
    return 0;
}
