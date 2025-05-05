#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int r,c,k,o;
    cin >> r >> c >> k;
    queue<pair<int,int>> q;
    vector<vector<int>> v(r,vector<int> (c));
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            cin >> o;
            v[i][j] = o;
            if(o){q.push(make_pair(i,j));}
        }
    }

    int t = 0;
    while(!q.empty() && t<k){
        int sz = q.size();
        for(int j = 0;j<sz;j++){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if(x+1 < r && v[x+1][y] == 0){q.push(make_pair(x+1,y));v[x+1][y] = 2;}
            if(x-1 >= 0 && v[x-1][y] == 0){q.push(make_pair(x-1,y));v[x-1][y] = 2;}
            if(y+1 < c && v[x][y+1] == 0){q.push(make_pair(x,y+1));v[x][y+1] = 2;}
            if(y-1 >= 0 && v[x][y-1] == 0){q.push(make_pair(x,y-1));v[x][y-1] = 2;}
        }
        t++;
    }

    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
}
