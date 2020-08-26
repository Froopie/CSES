#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 5e5 + 5;
 
using namespace std;
 
vector<int> ve[MAXN];
ll sz[MAXN], n;
ll ans[MAXN];
 
void dfsz(int u, int p) {
  sz[u] = 1;
  for (int v : ve[u])
    if (v != p) {
      dfsz(v, u);
      sz[u] += sz[v];
    }
}
 
ll dfss(int u, int p) {
  ll ret = 0;
  for (int v : ve[u])
    if (v != p) {
      ret += dfss(v, u);
      ret += sz[v];
    }
  return ret;
}
 
void dfs(int u, int p, ll w) {
  ans[u] = w;
  for (int v : ve[u])
    if (v != p)
      dfs(v, u, w+n-2*sz[v]);
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    ve[u].pb(v);
    ve[v].pb(u);
  }
  dfsz(1, 1);
  ll s = dfss(1, 1);
  dfs(1, 1, s);
  for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
  return 0;
}
