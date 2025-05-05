#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

bool hasCycle(int node, const vector<int>& parent, vector<bool>& visited, vector<bool>& onStack) {
    visited[node] = true;
    onStack[node] = true;

    int next = parent[node];
    if (next != -1) {
        if (!visited[next]) {
            if (hasCycle(next, parent, visited, onStack)) return true;
        } else if (onStack[next]) {
            return true;
        }
    }

    onStack[node] = false;
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, q, o;
    cin >> n >> q;

    for (int i = 0; i < q; i++) {
        vector<int> parent(n + 1, -1);
        vector<vector<int>> G(n+1);
        stack<int> root;
        int ans = 0;

        for (int j = 1; j <= n; j++) {
            cin >> o;
            parent[j] = o;
            if(o == -1){root.push(j);}
            else{G[o].push_back(j);}
        }

        vector<bool> visited(n + 1, false);
        vector<bool> onStack(n + 1, false);
        bool has_cycle = false;

        for (int k = 1; k <= n; k++) {
            if (!visited[k]) {
                if (hasCycle(k, parent, visited, onStack)) {
                    has_cycle = true;
                    break;
                }
            }
        }

        vector<bool> vst(n+1,false);

        while(!root.empty()){
            int r = root.top();
            root.pop();

            int cou = 0;
            queue<int> q;
            q.push(r);
            vst[r] = true;
            while(!q.empty()){
                int u = q.front();
                q.pop();

                for(auto &f:G[u]){
                    if(!vst[f]){
                        vst[f] = true;
                        q.push(f);
                    }
                }cou++;
            }ans = max(ans,cou);
        }


        if (has_cycle) {
            cout << "0 0\n";
        } else {
            cout << "1 " << ans << "\n";
        }
    }

    return 0;
}
