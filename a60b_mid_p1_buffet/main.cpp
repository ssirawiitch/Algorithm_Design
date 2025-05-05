#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int f,w,n,o;
    cin >> f >> w >> n;
    vector<bool> table(n+1,false);
    for(int i = 0;i<f;i++){
        cin >> o;
        table[o] = true;
    }
    int ans = 0;
    for(int i = 1;i<=n;i++){
        if(table[i]){
            i += (2*w);
            ans++;
        }
    }
    cout << ans;
    return 0;
}
