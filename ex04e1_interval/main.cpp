#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> s(n);
    vector<int> e(n);
    vector<pair<int,int>> p;
    for(int i = 0;i<n;i++){
        cin >> s[i];
    }
    for(int i = 0;i<n;i++){
        cin >> e[i];
    }
    for(int i = 0;i<n;i++){
        p.push_back({e[i],s[i]});
    }
    sort(p.begin(),p.end());

    int temp_e = 0;
    int ans = 0;
    for(int i = 0;i<n;i++){
        if(p[i].second >= temp_e){
            temp_e = p[i].first;
            ans++;
        }
    }
    cout << ans;
    return 0;
}
