#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 2e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
int n, p[MAXN], t;
bool incyc[MAXN], cyc;
int comp[MAXN], sz[MAXN], len[MAXN], vis[MAXN];
 
void dfs(int u) {
  vis[u] = 1;
  if (vis[p[u]] == 1) {
    comp[u] = p[u];
    comp[p[u]] = p[u];
    sz[p[u]] = 1;
    incyc[u] = incyc[p[u]] = 1;
    cyc = (u != p[u]);
  }
  else if (vis[p[u]] == 2) {
    comp[u] = comp[p[u]];
    len[u] = len[p[u]]+1;
  } else {
    dfs(p[u]);
    comp[u] = comp[p[u]];
    incyc[u] = cyc;
    sz[comp[u]] += cyc;
    if (!cyc)
      len[u] = len[p[u]]+1;
    if (u == comp[u]) cyc = 0;
  }
  vis[u] = 2;
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> p[i];
  for (int i = 1; i <= n; i++)
    if (!vis[i]) cyc = 0, dfs(i);
  for (int i = 1; i <= n; i++)
    if (incyc[i]) cout << sz[comp[i]] << ' ';
    else cout << len[i]+sz[comp[i]] << ' ';
  return 0;
}
