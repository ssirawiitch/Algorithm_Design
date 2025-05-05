#include <iostream>

using namespace std;

void recur(string s,int c,int n,int k,bool check){
    if(s.size() > n){return;}
    if(c>=k) {check=true;}
    if(s.size() == n && check){
        cout << s << endl;
        return;
    }
    recur(s+"0",0,n,k,check);
    recur(s+"1",c+1,n,k,check);
}

int main()
{
    int n,k;
    bool check = false;
    cin >> n >> k;
    recur("",0,n,k,check);
}
