#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int recur(vector<int> &v,int remain,int index){

    if(index<0){return INT_MIN;}
    if(remain == 0){
        return 0;
    }
    if(remain >= v[index]){
        int c = 1 + recur(v,remain - v[index],index);
        int nc = recur(v,remain,index-1);
        return max(c,nc);
    }else{
        return recur(v,remain,index-1);
    }


}

int main()
{
    int n,a,b,c;
    vector<int> v(3);
    cin >> n >> a >> b >> c;
    v[0] = a;v[1] = b;v[2] = c;
    sort(v.begin(),v.end());
    int result = recur(v, n, v.size() - 1);
    cout << (result == INT_MIN ? 0 : result) << endl;
}
