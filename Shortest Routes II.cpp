#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 5e2 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
ll dist[MAXN][MAXN];
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  memset(dist, -1, sizeof dist);
  while (m--) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    if (dist[u][v] == -1)
      dist[u][v] = dist[v][u] = w; 
    dist[u][v] = dist[v][u] = min(dist[u][v], w);
  }
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        if (dist[i][k] != -1 && dist[k][j] != -1) {
          if (dist[i][j] == -1) dist[i][j] = dist[i][k]+dist[k][j];
          dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
        }
  while (q--) {
    int u, v;
    cin >> u >> v;
    if (u == v) cout << 0 << '\n';
    else
    cout << dist[u][v] << '\n';
  }
  return 0;
}