#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

int n;

long long prim(vector<vector<pair<int,int>>> &v){

    long long ans = 0;
    vector<int> cost(n,INT_MIN);
    vector<int> taken(n,0);
    priority_queue<pair<int,int>> pq;

    pq.push({0,0});

    while(!pq.empty()){
        auto [c,u] = pq.top();
        pq.pop();

        if (taken[u]) continue;
        taken[u] = 1;
        ans += c;

        for(auto &[x,y] : v[u]){
            if (!taken[x] && y>cost[x]) {
                cost[x] = y;
                pq.push({y, x});
            }
        }
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);

    cin >> n;
    vector<int> beau(n);
    vector<vector<pair<int,int>>> v(n);

    for(int i = 0;i<n;i++){
        cin >> beau[i];
    }

    // find all cost between city
    for(int i = 0;i<n-1;i++){
        for(int j = i+1;j<n;j++){
            int b = beau[i] ^ beau[j];
            v[i].push_back({j,b});
            v[j].push_back({i,b});
        }
    }

    cout << prim(v);
}
