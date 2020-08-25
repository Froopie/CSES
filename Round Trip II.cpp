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
bool can;
int vis[MAXN];
 
void dfs(int u, int p=0) {
  if (can || vis[u] == 2) return;
  par[u] = p;
  if (vis[u]) {
    can = 1;
    node = u;
    return;
  }
  vis[u] = 1;
  for (int v : ve[u])
    dfs(v,u);
  vis[u] = 2;
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
  reverse(all(v));
  cout << v.size()+1 << '\n';
  cout << node << ' ';
  for (int k : v)
    cout << k << ' ';
  return 0;
}