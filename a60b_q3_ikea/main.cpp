#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,e,a,b,t;
    cin >> n >> e;
    vector<vector<int>> v(n+1);
    vector<int> deg(n+1,0);
    for(int i = 1;i<=e;i++){
        cin >> a >> b;
        v[a].push_back(b);
        deg[b]++;
    }
    for(int k = 0;k<5;k++){
        bool cmd = true;
        queue<int> q;
        vector<int> in_deg = deg;
        for(int i = 1;i<=n;i++){
            cin >> t;
            q.push(t);
        }

        while(q.size()>1){
            int f = q.front();
            q.pop();
            if(in_deg[f] != 0){cmd = false;break;}

            for(auto &x:v[f]){
                in_deg[x]--;
            }
        }
        if(cmd){cout << "SUCCESS" << "\n";}else{cout << "FAIL" << "\n";}
    }
}
