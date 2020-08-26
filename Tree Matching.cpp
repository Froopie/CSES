#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 5e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
vector<int> ve[MAXN];
int dp[2][MAXN];
 
int rec(bool k, int u, int p) {
  int &ret = dp[k][u];
  if (ret != -1) return ret;
  int tot = 0;
  for (int v : ve[u])
    if (v != p)
      tot += rec(1, v, u);
  ret = tot;
  if (!k) return ret;
  for (int v : ve[u])
    if (v != p)
      ret = max(ret, 1+tot-dp[1][v]+rec(0, v, u));
  return ret;
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  memset(dp, -1, sizeof dp);
  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    ve[u].pb(v);
    ve[v].pb(u);
  }
  cout << rec(1, 1, 1);
  return 0;
}