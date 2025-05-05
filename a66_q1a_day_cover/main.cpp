#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n,m;
int min_students = INT_MAX;
vector<vector<int>> v;

void myrecur(int start,int countt,vector<int> &day){

    if (all_of(day.begin(), day.end(), [](int x) { return x == 0; })) {
        min_students = min(min_students, countt);
        return;
    }

    if (start == m || countt >= min_students) return;

    // ลองไม่เลือกคนนี้
    myrecur(start + 1, countt, day);

    // ลองเลือกคนนี้
    vector<int> new_day = day;
    for (int x : v[start]) new_day[x] = 0;
    myrecur(start + 1, countt + 1, new_day);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int x,y;
    cin >> n >> m;
    vector<int> day(n,1);
    for(int i = 0;i<m;i++){
        cin >> x;
        vector<int> temp;
        for(int j = 0;j<x;j++){
            cin >> y;
            --y;
            temp.push_back(y);
        }
        v.push_back(temp);
    }
    myrecur(0, 0, day);
    cout << min_students << endl;
}
