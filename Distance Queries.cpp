#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 2e5 + 5;
 
using namespace std;
 
vector<int> ve[MAXN];
int L[MAXN], p[MAXN][19];
 
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
 
int lca(int u, int v) {
  if (L[u] < L[v]) swap(u,v);
  int ans = 0;
  for (int i = 18; i >= 0; i--)
    if (L[u]-(1<<i) >= L[v]) {
      ans += (1<<i);
      u = p[u][i];
    }
  if (u == v) return ans;
  for (int i = 18; i >= 0; i--)
    if (p[u][i] != p[v][i]) {
      ans += (1<<(i+1));
      u = p[u][i];
      v = p[v][i];
    }
  return ans+2;
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  n--;
  while (n--) {
    int u, v;
    cin >> u >> v;
    ve[u].pb(v);
    ve[v].pb(u);
  }
  dfs(1, 1, 0);
  while (q--) {
    int u, v;
    cin >> u >> v;
    cout << lca(u,v) << '\n';
  }
  return 0;
}