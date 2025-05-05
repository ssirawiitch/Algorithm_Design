#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void floyd(vector<vector<int>> &v,int n,bool &is_nc){

    for(int k = 0;k<n;k++){
        for(int j = 0;j<n;j++){
            for(int i = 0;i<n;i++){
                if(v[i][k] != INT_MAX && v[k][j] != INT_MAX){
                    v[i][j] = min(v[i][j],v[i][k] + v[k][j]);
                }
            }
        }
    }

    for(int i = 0;i<n;i++){
        if(v[i][i] < 0){
            is_nc = true;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,e,s;
    cin >> n >> e >> s;
    vector<vector<int>> v(n,vector<int> (n,INT_MAX));

    for (int i = 0; i < n; ++i) v[i][i] = 0; // trivial case
    for(int i = 0;i<e;i++){
        int a,b,w;
        cin >> a >> b >> w;
        v[a][b] = w;
    }

    bool is_nc = false;
    floyd(v,n,is_nc);

    if(is_nc){cout << -1;}
    else{
        for(int k = 0;k<n;k++){
            cout << v[s][k] << " ";
        }
    }
}
