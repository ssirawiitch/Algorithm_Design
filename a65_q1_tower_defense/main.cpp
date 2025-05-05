#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n,m,k,w;
    int ans = 0;
    cin >> n >> m >> k >> w;
    vector<pair<int,int>> store_mon;
    for(int i = 0;i<m;i++){
        int mon_pos;
        cin >> mon_pos;
        store_mon.push_back(make_pair(mon_pos,0));
    }
    for(int i = 0;i<m;i++){
        int mon_hp;
        cin >> mon_hp;
        store_mon[i].second = mon_hp;
        ans+=mon_hp;
    }
    for(int i = 0;i<k;i++){
        int pos ;
        cin >> pos;
        for(int j = 0;j<m;j++){
            if(abs(pos - store_mon[j].first) <= w && store_mon[j].second>=0){
                store_mon[j].second--;
                ans--;
                break;
            }
        }
    }
    cout << ans;
}
