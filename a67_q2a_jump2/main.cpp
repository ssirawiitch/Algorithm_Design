#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{

    int n,k;
    cin >> n >> k;
    vector<int> v(n+1);
    vector<int> b(k+1);
    vector<int> memo(n+1,0);

    for(int i = 1;i<=n;i++){
        cin >> v[i];

    }
    for(int i = 1;i<=k;i++){
        cin >> b[i];
    }

    memo[1] = v[1];
    memo[2] = memo[1] + v[2] - b[1];

    for(int i = 3;i<=n;i++){
        int ans = INT_MIN;

        for(int j = 1;j<=k;j++){

            int dif = i-j;
            if(dif > 0){
                int t = memo[i - j] + v[i] - b[j];
                ans = max(ans,t);
            }else{continue;}
        }
        memo[i] = ans;
    }

    cout << memo[n];

    return 0;
}
