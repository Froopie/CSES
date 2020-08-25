#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 1e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
int p[MAXN], sz[MAXN],comps, maxi;
 
void init(int n) {
  for (int i = 1; i <= n; i++) {
    p[i] = i;
    sz[i] = 1;
  }
}
 
int find(int u) {
  return p[u] = (p[u] == u? u : find(p[u]));
}
 
void unio(int u, int v) {
  if (find(u) == find(v)) return;
  comps--;
  if (sz[p[u]] < sz[p[v]]) swap(u,v);
  sz[p[u]] += sz[p[v]];
  p[p[v]] = p[u];
  maxi = max(maxi,sz[p[u]]);
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  comps = n;
  init(n);
  while (m--) {
    int u, v;
    cin >> u >> v;
    unio(u,v);
    cout << comps << ' ' << maxi << '\n';
  }
  return 0;
}