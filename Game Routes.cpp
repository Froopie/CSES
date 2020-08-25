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
int dp[MAXN];
 
void dfs(int u) {
  if (vis[u]) return;
  vis[u] = 1;
  if (u == n) {
    dp[u] = 1;
    return;
  }
  for (int v : ve[u]) {
    dfs(v);
    dp[u] = (dp[u]+dp[v])%mod;
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
  cout << dp[1];
  return 0;
}
