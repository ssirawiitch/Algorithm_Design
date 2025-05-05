#include <iostream>
#include <vector>

using namespace std;

int p(int i,int j,vector<vector<int>> &v,vector<vector<int>> &s,vector<vector<bool>> &c){

    if(i < 0 || j < 0){return 0;}
    if(c[i][j]){return s[i][j];}

    s[i][j] = p(i-1,j,v,s,c) + p(i,j-1,v,s,c) - p(i-1,j-1,v,s,c) + v[i][j];
    c[i][j] = true;
    return s[i][j];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<int>> v(n,vector<int> (m));
    vector<vector<int>> s(n,vector<int> (m,-1));
    vector<vector<bool>> c(n,vector<bool> (m,false));

    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> v[i][j];
        }
    }
    while(k--){
        int r1,c1,r2,c2;
        cin >> r1 >> c1 >> r2 >> c2;
        cout << p(r2,c2,v,s,c) - p(r1-1,c2,v,s,c) - p(r2,c1-1,v,s,c) + p(r1-1,c1-1,v,s,c) << "\n";
    }

    return 0;
}
