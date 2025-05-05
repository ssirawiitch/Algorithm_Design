#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,o;
    cin >> n;
    vector<int> v(n+1,0);
    vector<int> s(n+1,0);
    int x = n;
    for(int i = 1;i<=n;i++){
        cin >> o;
        v[i] = o;
        s[i] = o;
    }
    sort(s.begin(),s.end());
    vector<vector<int>> memo(n+1,vector<int> (n+1));

    // trivial case
    for(int i = 0;i<=x;i++){
        memo[i][0] = 0;
        memo[0][i] = 0;
    }

    // dp
    for(int i = 1;i<=x;i++){
        for(int j = 1;j<=x;j++){
            if(v[i-1] == s[j-1]){
                memo[i][j] = memo[i-1][j-1] + 1;
            }else{
                memo[i][j] = max(memo[i-1][j],memo[i][j-1]);
            }
        }
    }

    cout << memo[n][n];
    return 0;
}
