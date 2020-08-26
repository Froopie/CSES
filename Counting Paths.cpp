#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 2e5 + 5;
 
using namespace std;
 
vector<int> ve[MAXN];
int L[MAXN], p[MAXN][19], add[MAXN], sub[MAXN], ans[MAXN];
 
void dfs(int u, int pa, int w) {
  L[u] = w;
  for (int i = 1; (1<<i) <= w; i++)
    p[u][i] = p[p[u][i-1]][i-1];
  for (int v : ve[u])
    if (v != pa) {
      p[v][0] = u;
      dfs(v, u, w+1);
    }
}
 
int dfs2(int u, int p) {
  int w = add[u]-sub[u];
  for (int v : ve[u])
    if (v != p)
      w += dfs2(v, u);
  ans[u] = w;
  return w;
}
 
int lca(int u, int v) {
  if (L[u] < L[v]) swap(u,v);
  for (int i = 18; i >= 0; i--)
    if (L[u]-(1<<i) >= L[v])
      u = p[u][i];
  if (u == v) return u;
  for (int i = 18; i >= 0; i--)
    if (p[u][i] != p[v][i]) {
      u = p[u][i];
      v = p[v][i];
    }
  return p[u][0];
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    ve[u].pb(v);
    ve[v].pb(u);
  }
  dfs(1, 1, 0);
  while (q--) {
    int u, v;
    cin >> u >> v;
    int l = lca(v,u);
    sub[l]++;
    sub[p[l][0]]++;
    add[v]++; add[u]++;
  }
  dfs2(1, 1);
  for (int i = 1; i <= n; i++)
    cout << ans[i] << ' ';
  return 0;
}
