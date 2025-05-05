#include<bits/stdc++.h>

using namespace std;
const int INF = 2e9;
const int N = 710;

int geo[2][N][N],vst[2][N][N];
int num,sum;
int R,C,K;

void dfs(int r,int c,int pole)
{
    vst[pole][r][c] = true;
    if(!pole)num++;
    else sum++;
    int dir[][2] = {{r-1,c},{r+1,c},{r,c+1},{r,c-1}};
    for(int i = 0 ; i != 4 ;i++)
    {
        int dr = dir[i][0];
        int dc = dir[i][1];
        if(dr<1 || dr>R || dc<1 || dc>C || geo[pole][dr][dc])continue;
        if(!vst[pole][dr][dc])dfs(dr,dc,pole);
    }
}
int main()
{

    cin>>R>>C>>K;
    for(int i = 1 ; i<=R ; i++)
    {
        for(int j = 1 ; j<=C ; j++)
        {
            cin>>geo[0][i][j];
        }
    }
    for(int i = 1 ; i<=R ; i++)
    {
        for(int j = 1 ; j<=C ; j++)
        {
            cin>>geo[1][i][j];
        }
    }
    dfs(1,1,0);
    vector<pair<int,int>> s;
    for(int i = 0 ; i!=K ; i++)
    {
        int a,b;
        cin>>a>>b;
        s.push_back(make_pair(a,b));
    }
    int maxx = 0;
    for(auto [a,b] : s)
    {
        sum = 0;
        if(vst[0][a][b]){
            dfs(a,b,1);
            maxx = max(sum,maxx);
        }
    }
    num+=maxx;
    cout<<num;
}
