#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int n,a;
    cin >> n >> a;
    int sum = a;
    int ans = a;
    unordered_map<int,int> mp;
    mp[a] = 0;
    n--;
    while( n--){
        int a;
        cin >> a;
        ans = max(ans,a);
        if(!mp.count(a)){
            mp[a] = sum;
        }
        else{
            ans = max(ans , sum + a - mp[a]);
            mp[a] = min(mp[a] , sum);
        }
        sum += a;
    }
    cout << ans;

}

