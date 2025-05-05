#include <iostream>
#include <vector>

using namespace std;

const int MOD = 100000007;

void recur(int n,int k,int &co,int pos,int len){
    if(len >= n){co = (co+1)%MOD;return;}

    // start with 0
    recur(n,k,co,pos,len+1);

    // start with 1
    if(pos == -1 || (len - pos) >= k){
        recur(n,k,co,len,len+1);
    }
}

int main()
{
    int n,k;
    int  co = 0;
    cin >> n >> k;
    recur(n,k,co,-1,1);
    recur(n,k,co,0,1);
    cout << co% MOD;
}
