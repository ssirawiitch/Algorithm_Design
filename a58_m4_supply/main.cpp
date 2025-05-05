#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int main()
{
    int n,m,k,d,e,l;
    cin >> n >> m >> k;
    map<int,pair<int,int>> day;
    queue<int> sh_q;
    queue<int> st_q;
    for(int i = 1;i<=k;i++){
        cin >> d >> e >> l;
        day[d] = {e,l};
    }

    auto it = day.begin();
    for(;it!=day.end();it++){
        int cmd = (it->second).first;
        int g = (it->second).second;

        if(!cmd){
            if(sh_q.empty()){
                st_q.push(g);
                cout << 0 << "\n";
            }else{
                cout << sh_q.front() << "\n";
                sh_q.pop();
            }
        }else{
            if(st_q.empty()){
                sh_q.push(g);
                cout << 0 << "\n";
            }else{
                cout << st_q.front() << "\n";
                st_q.pop();
            }
        }
    }
    return 0;
}
