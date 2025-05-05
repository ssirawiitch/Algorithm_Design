#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> p(n);
    vector<int> f(k);
    vector<vector<int>> v(n);
    vector<int> visited(n,0);

    for(int i = 0;i<n;i++){
        cin >> p[i];
    }
    for(int i = 0;i<k;i++){
        cin >> f[i];
    }
    for(int i = 0;i<m;i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
    }

    for(int i = 0;i<k;i++){

        queue<int> q;
        q.push(f[i]);
        visited[f[i]] = 1;

        while(!q.empty()){
            int u = q.front();
            p[u] = 0;
            q.pop();

            for(auto &y:v[u]){
                if(!visited[y]){
                    visited[y] = 1;
                    q.push(y);
                }
            }
        }

        int ans = 0;

        for(auto q:p){
            ans+=q;
        }
        cout << ans << " ";
    }
}
