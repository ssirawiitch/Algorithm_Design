#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n,m,k;
int ans = 1e9;

void recur(int step,int cur,int total,vector<bool> &vst,vector<int> &v){

    if(step > m){return ;}

    if(step == m){
        ans = min(ans,abs(k-total));
        return;
    }
    // branch and bound
    int x = abs(k-total)/(m-step);
    auto it = lower_bound(v.begin(),v.end(),x);
    if(total + (m-step)*(*it) > ans){return ;}

    for(int i = cur+1;i<n;i++){
        if(!vst[i]){
            vst[i] = true;
            recur(step+1,i,total + v[i],vst,v);
            vst[i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> k;
    vector<int> v(n);
    for(int i = 0;i<n;i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    vector<bool> vst(n,false);
    recur(0,-1,0,vst,v);
    cout << ans;
    return 0;
}
