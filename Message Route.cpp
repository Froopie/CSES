#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 1e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
vector<int> ve[MAXN];
int par[MAXN], dist[MAXN];
 
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
  queue<int> qe;
  qe.push(1);
  memset(dist,-1,sizeof dist);
  dist[1] = 0;
  while (qe.size()) {
    int k = qe.front();
    qe.pop();
    for (int v : ve[k])
      if (dist[v] == -1) {
        qe.push(v);
        dist[v] = dist[k]+1;
        par[v] = k;
      }
  }
  if (dist[n] == -1) {
    cout << "IMPOSSIBLE";
    return 0;
  }
  int k = n;
  cout << dist[n]+1 << '\n';
  vector<int> path;
  path.pb(n);
  while (k != 1) {
    k = par[k];
    path.pb(k);
  }
  reverse(all(path));
  for (int c : path)
    cout << c << ' ';
  return 0;
}