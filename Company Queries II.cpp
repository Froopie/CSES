#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 2e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
vector<int> ve[MAXN];
int bz, level[MAXN], sqrtP[MAXN], p[MAXN];
 
void dfs(int u, int sqrtp, int l) {
  level[u] = l;
  sqrtP[u] = sqrtp;
  int newp = sqrtp;
  if (l%bz == 0)
    newp = u;
  for (int v : ve[u])
    dfs(v, newp, l+1);
}
 
int lca(int u, int v) {
  if (level[u] < level[v]) swap(u,v);
  while (level[sqrtP[u]] >= level[v])
    u = sqrtP[u];
  while (level[u] > level[v])
    u = p[u];
  if (u == v) return u;
  while (sqrtP[u] != sqrtP[v]) {
    u = sqrtP[u];
    v = sqrtP[v];
  }
  while (p[u] != p[v]) {
    u = p[u];
    v = p[v];
  }
  return p[u];
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  bz = sqrt(n);
  for (int i = 2; i <= n; i++) {
    int u;
    cin >> u;
    p[i] = u;
    ve[u].pb(i);
  }
  dfs(1,0,1);
  while (q--) {
    int a, b;
    cin >> a >> b;
    cout << lca(a,b) << '\n';
  }
  return 0;
}