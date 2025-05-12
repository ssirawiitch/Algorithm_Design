#include <bits/stdc++.h>
using namespace std;
const int N=400005;
bool f[N];
vector<int> ans;

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,cnt=0;
    cin >> n;
    for (int i=1;i<=n*2-1;i++){
        int a;
        cin >> a;
        f[i]=a-1;
        if (i<=n && !f[i]) cnt++;
    }
    int p1=n,p2=n*2-1;
    while (cnt<n){
        while (!f[p1]){
            p1--;
            if (p1<1) p1+=n;
            ans.emplace_back(1);
        }
        while (f[p2]){
            p2--;
            ans.emplace_back(2);
        }
        cnt++;
        p2--;
        ans.emplace_back(2);
        f[p1]=0;
    }
    cout << ans.size() << '\n';
    for (auto e:ans) cout << e << ' ';
}
