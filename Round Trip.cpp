#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 1e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
vector<int> ve[MAXN];
int par[MAXN], node;
bool can, vis[MAXN];
 
void dfs(int u, int p) {
  if (can) return;
  par[u] = p;
  if (vis[u]) {
    can = 1;
    node = u;
    return;
  }
  vis[u] = 1;
  for (int v : ve[u])
    if (v != p)
      dfs(v, u);
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  while (m--) {
    int u, v;
    cin >> u >> v;
    ve[u].pb(v);
    ve[v].pb(u);
  }
  for (int i = 1; i <= n; i++)
    if (!vis[i])
      dfs(i, -1);
  if (!can) {
    cout << "IMPOSSIBLE";
    return 0;
  }
  int u = par[node];
  vector<int> v = {node};
  while (u != node) {
    v.pb(u);
    u = par[u];
  }
  cout << v.size()+1 << '\n';
  for (int k : v)
    cout << k << ' ';
  cout << node;
  return 0;
}