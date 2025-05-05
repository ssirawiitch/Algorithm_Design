#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,q,num,t,ans;
    vector<pair<int,int>> v;
    vector<int> store;
    cin >> n >> q;
    for(int i = 0;i<n;i++){
        cin >> num >> t;
        v.push_back(make_pair(num,t));
    }
    sort(v.begin(),v.end());
    int x = 0;
    for(int i = 0;i<n;i++){
        store.push_back(x + v[i].second);
        x+=v[i].second;
    }
    for(int i = 0;i<q;i++){
        cin >> ans;
        auto it = lower_bound(store.begin(),store.end(),ans);
        cout << v[it-store.begin()].first << endl;
    }
}
