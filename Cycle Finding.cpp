#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 2500 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
struct edge{
  int u, v; 
  ll w;
  edge(int a, int b, ll c) {u = a; v = b; w = c;}
};
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<edge> ve;
  ll dist[MAXN] = {};
  int p[MAXN];
  int n, m;
  cin >> n >> m;
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    ve.pb(edge(u, v, w));
  }
  int x;
  for (int i = 0; i < n; i++) {
    x = -1;
    for (edge e : ve)
      if (dist[e.v] > dist[e.u]+e.w) {
        x = e.v;
        p[e.v] = e.u;
        dist[e.v] = dist[e.u]+e.w;
      }
  }
  if (x == -1) cout << "NO";
  else {
    for (int i = 0; i < n; i++)
      x = p[x];
    cout << "YES\n";
    vector<int> ans;
    int v = x;
    while (1) {
      ans.pb(v);
      if (v == x && ans.size() > 1) break;
      v = p[v];
    }
    reverse(all(ans));
    for (int i : ans) cout << i << ' ';
  }
  return 0;
}
