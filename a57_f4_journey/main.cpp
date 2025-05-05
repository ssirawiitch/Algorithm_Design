#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,o;
int m = 1e-9;
int ans = 1e-9;

void recur(int step,vector<vector<int>> &h,int total,vector<bool> &vst,int visited_count){

    if(visited_count > N-1){return;}
    if(visited_count == N-1){
        ans = max(ans,total);
        return ;
    }
    if(total + (N - visited_count -1 )*m < ans){return;}
    if(visited_count + 1 == N-1){
        // choose go to last node
        recur(step+1,h,total + h[step][N-1],vst,visited_count+1);
    }
    for(int i = 1;i<N-1;i++){
        if(!vst[i]){
            vst[i] = true;
            recur(i,h,total + h[step][i],vst,visited_count+1);
            vst[i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    vector<vector<int>> happiness(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> o;
            happiness[i][j] = o;
            m = max(m,o);
        }
    }

    vector<bool> vst(N,false);
    vst[0] = true;
    recur(0,happiness,0,vst,0);

    cout << ans;
    return 0;
}
