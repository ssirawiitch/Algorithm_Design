#include <cstdio>
#include <algorithm>
using namespace std;
int d[200200];
int pre[200200];
int main() {
    int i, j, n, k, m, p, w;
    scanf("%d %d %d", &n, &k, &m);
    for (i = 1; i <= n; i++) {
        scanf("%d",&d[i]);
        d[i] -= m;
        pre[i] = d[i] + pre[i-1];
    }
    while(k--) {
        scanf("%d %d", &p, &w);
        int index = lower_bound(pre, pre+n, w+pre[p-1]) - pre;
        printf("%d\n", index);
    }
    return 0;
}
