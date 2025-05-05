#include <iostream>
#include <vector>
#include <climits>
#include <map>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,a;
    int max_deg = INT_MIN;
    map<int,int> ans;
    cin >> n;
    vector<vector<int>> m(n,vector<int> (n));

    for(int i = 0;i<n;i++){
        int tmp = 0;
        for(int j = 0;j<n;j++){
            cin >> a;
            tmp += a;
        }
        if(tmp > max_deg){max_deg = tmp;}
        ans[tmp]++;
    }

    for(int i = 0;i<max_deg+1;i++){
        auto it = ans.find(i);
        if(it != ans.end()){
            cout << ans[i] << " ";
        }else{cout << 0 << " ";}
    }
}
