#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 1e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
vector<int> ve[MAXN], topo;
bool cyc;
int vis[MAXN];
 
void dfs(int u) {
  if (vis[u] == 1) {
    cyc = 1;
    return;
  }
  if (vis[u]) return;
  vis[u] = 1;
  for (int v : ve[u])
    dfs(v);
  topo.pb(u);
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
    ve[v].pb(u);
  }
  for (int i = 1; i <= n; i++)
    if (!vis[i])
      dfs(i);
  if (cyc) cout << "IMPOSSIBLE";
  else
    for (int k : topo) cout << k << ' ';
  return 0;
}