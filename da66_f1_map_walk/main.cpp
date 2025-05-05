#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void way(string cur ,int i,int j , vector<vector<int> >& v){
    if(i < 0 || i > v.size()-1 || j> v[0].size()-1 || v[i][j] == 1){
        return ;
    }
    if(i == v.size()-1 && j == v[0].size()-1){
        cout <<cur<<'\n';
    }
    v[i][j] = 1;
    way(cur+"A" , i ,j+1 ,v);
    way(cur+"B" ,i+1 ,j,v);
    way(cur+"C",i-1,j ,v);
    v[i][j] = 0;
}
int main(){
    int r,c;
    cin >> r>> c;
    vector<vector<int> > v(r,vector<int>(c));
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            int p ;
            cin >> p;
            v[i][j] = p;
        }
    }
    way("",0,0,v);
    cout << "DONE";

}
