#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    string x,y;
    cin >> x >> y;
    int a = x.size();
    int b = y.size();
    vector<vector<int>> memo(a+1,vector<int> (b+1,-1));

    // trivial case
    for(int i = 0;i<=a;i++){
        memo[i][0] = 0;
    }
    for(int i = 0;i<=b;i++){
        memo[0][i] = 0;
    }

    // dp
    for(int i = 1;i<=a;i++){
        for(int j = 1;j<=b;j++){
            if(x[i-1] == y[j-1]){
                memo[i][j] = memo[i-1][j-1] + 1;
            }else{
                memo[i][j] = max(memo[i-1][j],memo[i][j-1]);
            }
        }
    }
    cout << memo[a][b];
    return 0;
}
