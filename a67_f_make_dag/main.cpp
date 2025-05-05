#include <iostream>

using namespace std;

int main()
{
    int n,m,a,b;
    cin >> n >> m;

    for(int i = 0;i<m;i++){
        cin >> a >> b;
        if(a >= b){
            cout << 1 << " ";
        }else{
            cout << 0 << " ";
        }
    }

}
