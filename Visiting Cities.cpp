#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 2e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
vector<pair<int,ll>> ve[MAXN];
vector<int> g[MAXN];
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
  topo(n);
  reverse(all(top));
  ll cur = 1;
  dp[n] = 1;
  vector<int> ans;
  for (int u : top) {
    if (cur == dp[u]) {
      ans.pb(u);
      cur = 1;
      dp[u] = 1;
    }
    cur += dp[u]*((ll)g[u].size()-1LL);
    for (int v : g[u]) {
      dp[v] += dp[u];
    }
  }
  sort(all(ans));
  cout << ans.size() << '\n';
  for (int k : ans) cout << k << ' ';
  return 0;
}