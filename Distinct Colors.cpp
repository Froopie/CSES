#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 5e5 + 5;
 
using namespace std;
 
set<int> se[MAXN];
vector<int> ve[MAXN];
int ans[MAXN], col[MAXN], sz[MAXN];
 
void dfsz(int u, int p) {
  sz[u] = 1;
  for (int v : ve[u])
    if (v != p) {
      dfsz(v, u);
      sz[u] += sz[v];
    }
}
 
void dfs(int u, int p) {
  int b = -1, s = 0;
  for (int v : ve[u])
    if (v != p) {
      dfs(v, u);
      if (sz[v] > s) {
        b = v;
        s = sz[v];
      }
    }
  if (b != -1) se[u].swap(se[b]);
  se[u].insert(col[u]);
  for (int v : ve[u])
    if (v != p && v != b)
      for (int k : se[v])
        se[u].insert(k);
  ans[u] = se[u].size();
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> col[i];
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    ve[u].pb(v);
    ve[v].pb(u);
  }
  dfsz(1, 1);
  dfs(1, 1);
  for (int i = 1; i <= n; i++)
    cout << ans[i] << ' ';
  return 0;
}
