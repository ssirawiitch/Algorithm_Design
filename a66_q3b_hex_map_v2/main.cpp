#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

// 6 directions
int dx_odd[] = {-1,-1,0,1,1,0};
int dy_odd[] = {0,1,1,1,0,-1};
int dx_even[] = {-1,-1,0,1,1,0};
int dy_even[] = {-1,0,1,0,-1,-1};

int main()
{
    int r,c,a1,b1,a2,b2;
    cin >> r >> c;
    vector<vector<int>> cost(r+1,vector<int> (c+1));
    cin >> a1 >> b1 >> a2 >> b2;
    for(int i = 1;i<=r;i++){
        for(int j = 1;j<=c;j++){
            cin >> cost[i][j];
        }
    }
    vector<vector<int>> dist(r+1,vector<int> (c+1,1e9));
    //vector<vector<pair<int,int>>> prev(r+1,vector<pair<int,int>> (c+1,{-1,-1}));
    priority_queue<tuple<int,int,int> , vector<tuple<int,int,int>> , greater<tuple<int,int,int>>> pq;
    // Dijkstra
    pq.push({cost[a1][b1],a1,b1});
    dist[a1][b1] = cost[a1][b1];
    while(!pq.empty()){
        auto [t,x,y] =  pq.top();
        pq.pop();
        for(int i = 0;i<6;i++){
            int new_x = x + ((x%2 == 0)? dx_even[i] : dx_odd[i]);
            int new_y = y + ((x%2 == 0)? dy_even[i] : dy_odd[i])    ;
            if(new_x >= 1 && new_y >= 1 && new_x <= r && new_y <= c){
                if(dist[new_x][new_y] > t + cost[new_x][new_y]){
                    dist[new_x][new_y] = t + cost[new_x][new_y];
                    //prev[new_x][new_y] = {x,y};
                    pq.push({dist[new_x][new_y],new_x,new_y});
                }
            }
        }
    }
    cout << dist[a2][b2];
    //int pos_x = a2;
    //int pos_y = b2;
    //while(prev[pos_x][pos_y] != make_pair(-1,-1)){
        //cout << prev[pos_x][pos_y].first << " " << prev[pos_x][pos_y].second << "-> ";
        //pos_x = prev[pos_x][pos_y].first;
        //pos_y = prev[pos_x][pos_y].second;
    //}
    return 0;
}
