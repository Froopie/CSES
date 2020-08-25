#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 2e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
vector<pair<int,ll>> ve[MAXN];
vector<int> g[MAXN], g2[MAXN];
vector<int> top;
ll dist[MAXN], dp[MAXN];
bool vis[MAXN];
int n, m;
 
void topo(int u) {
  if (vis[u]) return;
  vis[u] = 1;
  for (int v : g[u])
    topo(v);
  top.pb(u);
}
 
ll recmi(int u) {
  if (u == n) return 0;
  ll &ret = dp[u];
  if (ret != -1) return ret;
  ret = 1e12;
  for (int v : g2[u])
    ret = min(ret, 1+recmi(v));
  return ret;
}
 
ll recma(int u) {
  if (u == n) return 0;
  ll &ret = dp[u];
  if (ret != -1) return ret;
  ret = -1e12;
  for (int v : g2[u])
    ret = max(ret, 1+recma(v));
  return ret;
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  while (m--) {
    ll u, v, w;
    cin >> u >> v >> w;
    ve[u].pb({v,w});
  }
  for (int i = 0; i < MAXN; i++)
    dist[i] = 1e16;
  priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> qe;
  qe.push({0,1});
  dist[1] = 0;
  while (!qe.empty()) {
    auto t = qe.top();
    qe.pop();
    if (t.first > dist[t.second])
      continue;
    for (auto v : ve[t.second]) {
      if (dist[v.first] > v.second+t.first) {
        dist[v.first] = v.second+t.first;
        g[v.first].clear();
        qe.push({t.first+v.second, v.first});
      }
      if (dist[v.first] == v.second+t.first)
        g[v.first].pb(t.second);
    }
  }
  for (int i = 1; i <= n; i++)
    for (int v : g[i])
      g2[v].pb(i);
  topo(n);
  reverse(all(top));
  ll cur = 1;
  dp[n] = 1;
  for (int u : top)
    for (int v : g[u]) {
      dp[v] += dp[u];
      dp[v] %= mod;
    }
  cout << dist[n] << ' ' << dp[1] << ' ';
  memset(dp, -1, sizeof dp);
  cout << recmi(1) << ' ';
  memset(dp, -1, sizeof dp);
  cout << recma(1);
  return 0;
}
