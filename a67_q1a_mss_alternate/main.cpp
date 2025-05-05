#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,temp;
ll ans = LLONG_MIN, accu;
bool is_swap = false;
int reals[500010];
int qs_first[500010];
int qs_second[500010];

int get_sum(bool first, int st, int ed){
    if(first) {
        return qs_first[ed + 1] - qs_first[st];
    }else {
        return qs_second[ed + 1] - qs_second[st];
    }
}

int recru(int st, int ed) {
    if(st == ed) {
        return reals[st];
    }
    int m = (st + ed) >> 1;

    int r1 = recru(st, m);
    int r2 = recru(m+1, ed);

    int max_sum_left_first = get_sum(true, m, m);
    for(int i = st&1? st + 1: st;i <= m-1;i+=2) {
        max_sum_left_first = max(max_sum_left_first, get_sum(true, i, m));
    }

    int max_sum_left_second = get_sum(false, m-1, m);
    for(int i = st&1? st: st + 1;i <= m-3;i+=2) {
        max_sum_left_second = max(max_sum_left_second, get_sum(false, i, m));
    }

    int max_sum_right_first = get_sum(true, m+1, m+1);
    int max_sum_right_second = get_sum(false, m+1, m+1);
    for(int i = m+2; i <= ed;i++) {
        max_sum_right_first = max(max_sum_right_first, get_sum(true, m+1, i));
        max_sum_right_second = max(max_sum_right_second, get_sum(false, m+1, i));
    }

    int r3 = max_sum_left_first + max_sum_right_first;
    int r4 = max_sum_left_second + max_sum_right_second;

    return max(max(r1, r2), max(r3, r4));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for(int i = 0;i < n;i++) {
        cin >> temp;
        reals[i] = temp;
        qs_first[i + 1] = qs_first[i] + temp * (is_swap ? -1: 1);
        qs_second[i + 1] = qs_second[i] + temp * (is_swap ? 1: -1);
        is_swap = !is_swap;
    }

    cout << recru(0, n-1);

    return 0;
}
