#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> memo(n+1,0);
    vector<int> v(n+1,0);
    for(int i = 1;i<=n;i++){
        cin >> v[i];
    }
    // Trivial Case
    memo[1] = v[1];
    memo[2] = max(v[1],v[2]);

    // DP
    for(int i = 3;i<=n;i++){
        memo[i] = max(memo[i-3] + v[i],max(memo[i-2],memo[i-1]));
    }

    cout << memo[n];
}
