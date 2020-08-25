#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 1e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
vector<int> ve[MAXN];
bool vis[MAXN];
int n, m;
pair<int,int> dp[MAXN];
 
void dfs(int u) {
  if (vis[u]) return;
  vis[u] = 1;
  if (u == n) {
    dp[u] = {1,n};
    return;
  }
  for (int v : ve[u]) {
    dfs(v);
    if (dp[v].first)
    dp[u] = max(dp[u],{1+dp[v].first,v});
  }
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  while (m--) {
    int u, v;
    cin >> u >> v;
    ve[u].pb(v);
  }
  dfs(1);
  if (dp[n] == make_pair(0,0)) {
    cout << "IMPOSSIBLE";
    return 0;
  }
  vector<int> ans;
  int beg = 1;
  while (beg != n) {
    ans.pb(beg);
    beg = dp[beg].second;
  }
  ans.pb(beg);
  cout << ans.size() << '\n';
  for (int k : ans) cout << k << ' ';
  return 0;
}
