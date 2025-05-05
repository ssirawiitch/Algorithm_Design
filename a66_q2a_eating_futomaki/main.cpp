#include <iostream>
#include <vector>

using namespace std;

int recur(int index_l,int index_r,vector<int> &v,vector<vector<int>> &memo){

    if(index_l + 1 == index_r){return max(v[index_l],v[index_r]);}

    if(memo[index_l][index_r] != -1){return memo[index_l][index_r];}
    if(index_l >= index_r){return memo[index_l][index_r] = 0;}

    // choose l&r
    int lr = recur(index_l+1,index_r-1,v,memo) + max(v[index_l],v[index_r]);

    // choose both l
    int l = recur(index_l+2,index_r,v,memo) + max(v[index_l],v[index_l + 1]);

    // choose both r
    int r = recur(index_l,index_r-2,v,memo) + max(v[index_r],v[index_r - 1]);

    return memo[index_l][index_r] = max(max(lr,l),r);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    vector<vector<int>> memo(n,vector<int> (n,-1));
    for(int i = 0;i<n;i++){
        cin >> v[i];
    }
    cout << recur(0,n-1,v,memo);
}
