#include <iostream>
#include <vector>

using namespace std;

int recur(vector<vector<int>> &v,int n,int k){
    if(n == k) return 1;
    if(k == 0) return 1;

    if(v[n][k] != -1){return v[n][k];}

    int result = recur(v,n-1,k) + recur(v,n-1,k-1);

    v[n][k] = result;
    return result;
}

int main()
{
    int n,k;
    cin >> n >> k;
    vector<vector<int>> v(n+1, vector<int>(n+1,-1));

    cout << recur(v,n,k);
}
