#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 1e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
vector<int> ve[MAXN];
int g[MAXN];
bool can;
 
void dfs(int i, int m=0) {
  if (g[i] != -1 && g[i] != m)
    can = 1;
  if (g[i] != -1) return;
  g[i] = m;
  for (int v : ve[i])
    dfs(v,(m^1));
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
  memset(g,-1,sizeof g);
  for (int i = 1; i <= n; i++)
    if (g[i] == -1)
      dfs(i);
  if (can) {
    cout << "IMPOSSIBLE";
    return 0;
  }
  for (int i = 1; i <= n; i++)
    cout << g[i]+1 << ' ';
  return 0;
}