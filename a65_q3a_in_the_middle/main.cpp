#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

vector<int> bfs_t1;
vector<int> bfs_t2;
vector<int> bfs_t3;

void bfs(int start,vector<int> &v,vector<vector<int>> &g){

    queue<int> q;
    v[start] = 0;
    q.push(start);

    int t = 1;
    while(!q.empty()){
        int sz = q.size();
        for(int j = 1;j<=sz;j++){
            int f = q.front();
            q.pop();

            for(auto &x:g[f]){
                if(v[x] == -1){
                    v[x] = t;
                    q.push(x);
                }
            }
        }t++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,t1,t2,t3,o,a;
    cin >> n >> t1 >> t2 >> t3;
    vector<vector<int>> v(n+1);
    for(int i = 1;i<=n;i++){
        cin >> o;
        for(int j = 0;j<o;j++){
            cin >> a;
            v[i].push_back(a);
        }
    }

    // loop to get all BFS lenght
    bfs_t1.resize(n+1,-1);bfs_t2.resize(n+1,-1);bfs_t3.resize(n+1,-1);
    bfs(t1,bfs_t1,v);
    bfs(t2,bfs_t2,v);
    bfs(t3,bfs_t3,v);

    // loop find stop node;
    int ans = INT_MAX;
    for(int i = 1;i<=n;i++){
        int p1 = bfs_t1[i];
        int p2 = bfs_t2[i];
        int p3 = bfs_t3[i];
        if(p1 == -1 || p2 == -1 || p3 == -1){continue;}

        ans = min(ans,max({p1,p2,p3}));
    }

    cout << ans;
}
