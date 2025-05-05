#include <iostream>

using namespace std;

void recur(string s,int a,int b,int co,int track){
    if(track > b){return;}
    if(co == a && track == b){
        cout << s << endl;
        return;
    }
    recur(s+"0",a,b,co,track+1);
    recur(s+"1",a,b,co+1,track+1);
}

int main()
{
    int a,b;
    cin >> a >> b;
    recur("",a,b,0,0);
}
