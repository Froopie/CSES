#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 1e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
int n, m, c, comp[MAXN];
vector<int> kora, ve[MAXN], ev[MAXN];
bool vis[MAXN];
 
void dfs(int u) {
  if (vis[u]) return;
  vis[u] = 1;
  for (int k : ve[u])
    dfs(k);
  kora.pb(u);
}
 
void dfs2(int u) {
  if (vis[u]) return;
  vis[u] = 1;
  comp[u] = c;
  for (int k : ev[u])
    dfs2(k);
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    ve[u].pb(v);
    ev[v].pb(u);
  }
  for (int i = 1; i <= n; i++)
    dfs(i);
  reverse(all(kora));
  memset(vis,0,sizeof vis);
  for (int i = 0; i < n; i++)
    if (!vis[kora[i]]) {
      c++;
      dfs2(kora[i]);
    }
  cout << c << '\n';
  for (int i = 1; i <= n; i++)
    cout << comp[i] << ' ';
  return 0;
}
