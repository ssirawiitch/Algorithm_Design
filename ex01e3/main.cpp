#include <iostream>
#include <vector>

using namespace std;

int bi_s(vector<int> &v,int start,int stop,int a){
    int mid = (start+stop)/2;
    if(start+1 == stop){
        return (v[stop] <= a)? v[stop]:v[start];
    }

    if(v[mid] < a){
        return bi_s(v,mid+1,stop,a);
    }else{
        return bi_s(v,start,mid,a);
    }
}

int main()
{
    int n,m,a;
    cin >> n >> m;
    vector<int> v(n);
    for(int i = 0;i<n;i++){
        cin >> v[i];
    }
    for(int i = 0;i<m;i++){
        cin >> a;
        if(a<v[0]){cout << -1 << endl;}
        else if(a>v[v.size()-1]){cout << v[v.size()-1] << endl;}
        else{cout << bi_s(v,0,n-1,a) << endl;}
    }
}
