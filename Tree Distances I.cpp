#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 5e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
vector<int> ve[MAXN];
pair<int,int> dist[MAXN], nodes[MAXN];
 
void dfs(int u, int p) {
  for (int v : ve[u]) if (v != p) {
    dfs(v, u);
    if (dist[v].first+1 > dist[u].first) {
      dist[u].second = dist[u].first;
      nodes[u].second = nodes[u].first;
      dist[u].first = dist[v].first+1;
      nodes[u].first = v;
    }
    else if (dist[v].first+1 > dist[u].second) {
      dist[u].second = dist[v].first+1;
      nodes[u].second = v;
    }
  }
}
 
void dfs2(int u, int p) {
  if (u != p) {
    if (u != nodes[p].first) {
      if (dist[p].first+1 > dist[u].first) {
        dist[u].second = dist[u].first;
        nodes[u].second = nodes[u].first;
        dist[u].first = dist[p].first+1;
        nodes[u].first = p;
      }
      else if (dist[p].first+1 > dist[u].second) {
        dist[u].second = dist[p].first+1;
        nodes[u].second = p;
      }
    }
    if (u != nodes[p].second) {
      if (dist[p].second+1 > dist[u].first) {
        dist[u].second = dist[u].first;
        nodes[u].second = nodes[u].first;
        dist[u].first = dist[p].second+1;
        nodes[u].first = p;
      }
      else if (dist[p].second+1 > dist[u].second) {
        dist[u].second = dist[p].second+1;
        nodes[u].second = p;
      }
    }
  }
  for (int v : ve[u])
    if (v != p) dfs2(v, u);
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  for (int i = 0; i < n-1; i++) {
    int u, v; cin >> u >> v;
    ve[u].pb(v);
    ve[v].pb(u);
  }
  dfs(1, 1);
  dfs2(1, 1);
  for (int i = 1; i <= n; i++) cout << dist[i].first << ' ';
  return 0;
}