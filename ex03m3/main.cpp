#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int recur(vector<int> &memo,vector<int> &p,int n,int k,int index){

    if(index >= n){return 0;}

    if (memo[index] != -1) return memo[index];

    // choose
    int c = p[index] + recur(memo,p,n,k,index + 2*k +1);

    // not choose
    int nc = recur(memo, p, n, k, index + 1);

    return memo[index] = min(c,nc);
}

int main()
{
    int n,k;
    cin >> n >> k;
    vector<int> p(n);
    vector<int> memo(n,-1); // memo[i] min cost to pay at i index

    for(int i = 0;i<n;i++){
        cin >> p[i];
    }

    cout << recur(memo,p,n,k,0);
    return 0;
}
