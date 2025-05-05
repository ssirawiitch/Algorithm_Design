#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n,l,o;
    cin >> n >> l;
    vector<int> p(n);
    for(int i = 0;i<n;i++){
        cin >> p[i];
    }
    sort(p.begin(),p.end());
    int ans = 0;
    int t = p[0];
    for(int i = 0;i<n;i++){
        if(p[i] >= t){
            ans++;
            t = p[i]+l;
        }

    }
    cout << ans;
    return 0;
}
