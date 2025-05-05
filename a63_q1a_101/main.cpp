#include <iostream>
#include <vector>

const int MOD = 100000007;

using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector<vector<long long>> v(n+1,vector<long long> (4));
    v[0][0] = 0;v[0][1] = 0;v[0][2] = 0;v[0][3] = 0;
    v[1][0] = 0;v[1][1] = 0;v[1][2] = 0;v[1][3] = 0;
    v[2][0] = 1;v[2][1] = 1;v[2][2] = 1;v[2][3] = 1;
    v[3][0] = 2;v[3][1] = 1;v[3][2] = 2;v[3][3] = 2;

    for(int i = 4;i<=n;i++){
        v[i][0] = (v[i-1][0] + v[i-1][2]) % MOD;
        v[i][1] = (v[i-1][0]) % MOD;
        v[i][2] = (v[i-1][1] + v[i-1][3]) % MOD;
        v[i][3] = (v[i-1][1] + v[i-1][3]) % MOD;
    }

    cout << (v[n][0] + v[n][1] + v[n][2] + v[n][3]) % MOD;
}
