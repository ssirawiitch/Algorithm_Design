#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> a(n+1);
    vector<int> x(n+1);
    for(int i = 1;i<=n;i++){
        cin >> a[i];
    }

    for(int i = 0;i<m;i++){

        bool c = true;
        bool u = true;

        for(int j = 1;j<=n;j++){
            cin >> x[j];
        }

        int l = INT_MIN;
        int p = 0;

        for(int j = 1;j<=n;j++){
            if(a[x[j]] > l){
                l = a[x[j]];
            }else if(a[x[j]] == l){
                if(p!=0 ){
                    if(x[j] < p){u=false;}
                }else{
                    p = x[j];
                }
            }
            else{
                c= false;break;
            }

        }

        if(c){
            cout << 1 << " ";
            if(u){cout << 1 << endl;}
            else{cout << 0 << endl;}
        }else{
            cout << 0 << " " << 0 << endl;
        }
    }

}
