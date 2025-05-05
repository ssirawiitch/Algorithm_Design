#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m,u;
    cin >> n;
    vector<vector<int>> v(n);
    vector<int> deg(n);
    for(int i = 0;i<n;i++){
        cin >> m;
        for(int j = 0;j<m;j++){
            cin >> u;
            v[u].push_back(i);
            deg[i]++;
        }
    }

    vector<int> ans;
    queue<int> q;
    for(int i = 0;i<n;i++){
        if(deg[i] == 0){q.push(i);}
    }

    while(!q.empty()){
        int p = q.front();
        q.pop();
        ans.push_back(p);

        for(auto &x: v[p]){
            deg[x]--;
            if(deg[x] == 0){
                q.push(x);
            }
        }
    }

    for(auto &x:ans){
        cout << x << " ";
    }
}
