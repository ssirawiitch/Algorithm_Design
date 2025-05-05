#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

vector<long long> v;
map<long long,long long> m;
int main()
{
    long long n,o;
    cin >> n;
    for(int  i = 0;i<n;i++){
        cin >> o;
        v.push_back(o);
        m[o]++;
    }
    long long ans = 0;
    for(auto &x : m){
        if(x.second != 1){
            ans += pow(x.second,2);
        }
    }
    cout << ans;
}
