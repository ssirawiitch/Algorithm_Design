#include <iostream>
#include <vector>

using namespace std;

int recur(int i,vector<int> &v,vector<int> &st,int n){

    if(i == 0){return v[0];}
    if(i == 1){return max(v[1],v[0]+v[1]);}
    if(i == 2){
        int j = v[2] + v[1] + v[0];
        int k = v[2] + v[1];
        int l = v[2] + v[0];
        return max(max(v[2],j),max(k,l));
    }

    return max(max(recur(i-1,v,st,n),recur(i-2,v,st,n)),recur(i-3,v,st,n)) + v[i];
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> ans(n,0);
    for(int i = 0;i<n;i++){
        cin >> v[i];
    }
    cout << recur(n-1,v,ans,n-1);
}
