#include <iostream>
#include <vector>

using namespace std;

bool isVirus(int start,int stop,vector<int> &v){
    if(start + 1 == stop)return true;
    int mid = (start+stop)/2;
    bool left = isVirus(start,mid,v);
    int right = isVirus(mid+1,stop,v);

    int co = 0;
    for(int i = start;i<=mid;i++){
        co+=v[i];
    }
    for(int i = mid+1;i<=stop;i++){
        co-=v[i];
    }
    if(co>1 || co<-1){return false;}
    return left && right;
}

int main()
{
    int n,k,o;
    cin >> n >> k;
    int len = 1 << k;
    for(int i = 0;i<n;i++){
        vector<int> v(len);
        for(int j = 0;j<len;j++){
            cin >> v[j];
        }
        if(isVirus(0,v.size()-1,v)){cout << "yes" << endl;}
        else{cout << "no" << endl;}
    }
}
