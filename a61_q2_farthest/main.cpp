#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>

using namespace std;

int n;

void dijkstra(vector<vector<int>> &mat,int start,vector<int> &dist){

    set<pair<int,int>> s;
    dist[start] = 0;
    s.insert({0,start});

    while(!s.empty()){
        auto [t,u] = *(s.begin());
        s.erase(s.begin());

        for(int h = 0;h<n;h++){
            if(mat[u][h] != -1){
                if(dist[h] > t+mat[u][h]){
                    s.erase({dist[h],h});
                    dist[h] = t+mat[u][h];
                    s.insert({dist[h],h});
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    vector<vector<int>> mat(n,vector<int> (n));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> mat[i][j];
        }
    }

    vector<int> dist(n,INT_MAX);
    dijkstra(mat,0,dist);

    auto it = max_element(dist.begin()+1,dist.end());
    cout << *it;
}
