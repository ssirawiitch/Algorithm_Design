#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int n, k,q;
int ans = 1e9;
int min_cost = 1e9;
int max_num = -1e9;

struct Set {
    int price;
    vector<int> books;
};

vector<Set> sellers;

bool check(const vector<bool>& c) {
    for (int i = 1; i <= n; i++) {
        if (!c[i]) return false;
    }
    return true;
}

int count_unsuc(const vector<bool> &c){
    int co = 0;
    for(int i = 1;i<=n;i++){
        if(!c[i]){co++;}
    }
    return co;
}

void recur(int idx, vector<bool>& c, int total) {

    if (check(c)) {
        ans = min(ans, total);
        return;
    }
    if (idx == sellers.size()) return;

    // branch and bound
    int divide = count_unsuc(c)/max_num;
    if(divide * min_cost > ans){return;}

    // choose
    vector<int> changed;
    for (int book : sellers[idx].books) {
        if (!c[book]) {
            c[book] = true;
            changed.push_back(book);
        }
    }
    recur(idx + 1, c, total + sellers[idx].price);

    for (int book : changed) {
        c[book] = false;
    }

    // not choose
    recur(idx + 1, c, total);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    sellers.resize(k);

    for (int i = 0; i < k; i++) {
        int price, m;
        cin >> price >> m;
        min_cost = min(min_cost,price);
        max_num = max(max_num,m);
        sellers[i].price = price;
        sellers[i].books.resize(m);
        for (int j = 0; j < m; j++) {
            cin >> q;
            sellers[i].books[j] = q;
        }
    }

    vector<bool> c(n + 1, false);
    recur(0, c, 0);
    cout << ans << '\n';

    return 0;
}
