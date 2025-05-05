#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int recur(int step,vector<vector<int>> &F,vector<int> &B,vector<int> &used){
    if(step > n){return 0;}

    // choose
    int c = -1e9;
    bool can = true;
    for(auto &x:used){
        if(!F[step][x]){
            can = false;
        }
    }
    if(can){
        used.push_back(step);
        c = B[step] + recur(step+1,F,B,used);
        used.pop_back();
    }

    // not choose
    int nc = recur(step+1,F,B,used);

    return max(c,nc);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    vector<int> B(n+1,0);
    vector<vector<int>> F(n+1,vector<int> (n+1,0));
    vector<int> used;
    for(int i = 1;i<=n;i++){
        cin >> B[i];
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            cin >> F[i][j];
        }
    }
    cout << recur(1,F,B,used);
}
