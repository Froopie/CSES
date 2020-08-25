#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
#define x first
#define y second
const int MAXN = 1e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
vector<pair<int,ll>> ve[MAXN];
ll dist[MAXN];
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  while (m--) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    ve[u].pb({v,w});
  }
  memset(dist, -1, sizeof dist);
  priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
  pq.push({0,1});
  dist[1] = 0;
  while (pq.size()) {
    auto u = pq.top();
    pq.pop();
    if (dist[u.y] < u.x) continue;
    for (auto v : ve[u.y])
      if (dist[v.x] == -1 || dist[v.x] > dist[u.y]+v.y) {
        pq.push({dist[u.y]+v.y,v.x});
        dist[v.x] = dist[u.y]+v.y;
      }
  }
  for (int i = 1; i <= n; i++)
    cout << dist[i] << ' ';
  return 0;
}