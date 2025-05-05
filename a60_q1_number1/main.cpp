#include <iostream>
#include <deque>
#include <cmath>

using namespace std;

deque<int> recur(deque<int> q,bool c){
    deque<int> temp;
    deque<int> temp2;

    if(c){return temp2;}

    while(!q.empty()){
        if(q.front() != 0 || q.front() != 1){
            c = false;
        }
        q.pop_front();
    }

    int y = temp.front();
    temp2.push_front(floor(y/2));
    temp2.push_front(y%2);
    temp2.push_front(floor(y/2));
    recur(temp2,c);
}

int main()
{
    int n,l,r;
    cin >> n >> l >> r;
    deque<int> q;
    q.push_back(n);
    recur(q,true);

    int ans = 0;
    int track = 1;
    while(!q.empty()){
        if(q.front() == 1 && track >= l && track <= r){ans+=1;}
        track++;
    }
    cout << ans;
}
