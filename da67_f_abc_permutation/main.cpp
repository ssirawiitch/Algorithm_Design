#include <bits/stdc++.h>

using namespace std;

int n;
void recur(string s,int i,int j,int k,vector<string>& v){
    if(s.size() == n){
        v.emplace_back(s);
        return ;
    }
    if(i>0){
        recur(s + "A", i - 1, j, k,v);
    }
    if(j>0){
        recur(s + "B", i, j - 1, k,v);
    }
    if(k>0){
        recur(s + "C", i , j, k-1,v);
    }
}

int main()
{
    int i,j,k;
    vector<string> ans;
    cin >> n >> i >> j >> k;
    recur("",i,j,k,ans);
    cout << ans.size() << endl;
    for(auto x: ans) {
		cout << x << endl;
	}
}
