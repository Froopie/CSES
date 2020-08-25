#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 2e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
struct pr{
  ll s, e, r, next;
  bool operator<(const pr &a) {
    if (s != a.s) return s < a.s;
    return e < a.e;
  }
};
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pr> ve;
  for (int i = 0; i < n; i++) {
    pr k;
    cin >> k.s >> k.e >> k.r;
    ve.pb(k);
  }
  sort(all(ve));
  for (int i = 0; i < n; i++) {
    pr c;
    c.s = ve[i].e+1; c.e = -1;
    ve[i].next = lower_bound(all(ve), c)-ve.begin();
  }
  ll dp[MAXN] = {};
  dp[n-1] = ve[n-1].r;
  for (int i = n-2; i >= 0; i--) {
    dp[i] = max(dp[i+1], ve[i].r);
    if (ve[i].next != n) dp[i] = max(dp[i], ve[i].r+dp[ve[i].next]);
  }
  cout << dp[0];
  return 0;
}
