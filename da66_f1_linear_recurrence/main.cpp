#include <bits/stdc++.h>
using namespace std;
const int MOD = 32717;
const int INF = 1e8 + 5;

vector<int> a, c;
vector<int> dp;

int n, k;

int recur(int n) {
  if (dp[n] != -INF) return dp[n];

  if (n < k) return a[n];

  int sum = 0;
  for (int i = 0; i < k; i++) {
    sum += (c[i] * recur(n - i - 1)) % MOD;
    sum %= MOD;
  }

  dp[n] = sum;

  return sum;
}

int main() {
  cin >> k >> n;
  a.resize(k);
  c.resize(k);
  dp.resize(n + 1, -INF);

  for (int i = 0; i < k; i++) scanf("%d", &c[i]);
  for (int i = 0; i < k; i++) scanf("%d", &a[i]);

  cout << recur(n);
}
