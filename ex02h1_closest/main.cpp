#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int distance(int x1,int y1,int x2,int y2){
    return pow((x1-x2),2)+pow((y1-y2),2);
}

int recur(vector<pair<int,int>> &vx,int start,int stop){
    if (stop - start <= 3) {  // Base case: use brute force for small number of points
        int ans = 30000000;
        for (int i = start; i < stop; i++) {
            for (int j = i + 1; j < stop; j++) {
                ans = min(ans, distance(vx[i].first, vx[i].second, vx[j].first, vx[j].second));
            }
        }
        return ans;
    }
    int mid = (start+stop)/2;
    int l = recur(vx,start,mid);
    int r = recur(vx,mid+1,stop);
    int ans = min(l, r);

    vector<pair<int, int>> strip;
    for (int i = start; i < stop; i++) {
        if (abs(vx[i].first - vx[mid].first) < ans) {
            strip.push_back(vx[i]);
        }
    }

    for (int i = 0; i < strip.size(); i++) {
        for (int j = i + 1; j < strip.size() && (strip[j].second - strip[i].second) < ans; j++) {
            ans = min(ans, distance(strip[i].first, strip[i].second, strip[j].first, strip[j].second));
        }
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false),cin.tie(0);
    int n,x,y;
    cin >> n;
    vector<pair<int,int>> vx;
    for(int i = 0;i<n;i++){
        cin >> x >> y;
        vx.push_back(make_pair(x,y));
    }
    sort(vx.begin(),vx.end());
    cout << recur(vx,0,vx.size()-1);
}
