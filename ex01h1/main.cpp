#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> p(n);

    int max_p = 0;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        max_p = max(max_p, p[i]);
    }

    vector<int> memo(max_p+1,0);

    for(int i = 0;i<n;i++){
        for(int j = 0;j<i;j++){
            if(i+j >= max_p+1){break;}
            memo[i+j] = i+1;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << memo[p[i]-1] << "\n";
    }
}
