#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 1e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
struct edge{
  int u, v;
  ll w;
  edge(int a, int b, ll c) {
    u = a; v = b; w = c;
  }
  bool operator<(const edge &b) {
    return w < b.w;
  }
};
 
int p[MAXN];
 
void init(int n) {
  for (int i = 1; i <= n; i++)
    p[i] = i;
}
 
int find(int u) {
  return p[u] = (p[u] == u? u : find(p[u]));
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  init(n);
  vector<edge> ve;
  while (m--) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    ve.pb(edge(u,v,w));
  }
  sort(all(ve));
  ll ans = 0;
  for (auto k : ve) {
    if (find(k.u) == find(k.v)) continue;
    p[p[k.u]] = p[k.v];
    ans += k.w;
  }
  find(1);
  for (int i = 1; i <= n; i++)
    if (find(i) != p[1]) {
      cout << "IMPOSSIBLE";
      return 0;
    }
  cout << ans;
  return 0;
}