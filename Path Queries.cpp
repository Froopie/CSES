#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 2e5 + 5;
 
using namespace std;
 
vector<int> ve[MAXN];
ll val[MAXN], in[2*MAXN], out[2*MAXN], BIT[2*MAXN];
int t = 1;
 
void up(int i, ll v) {
  for (; i <= t; i += i&-i) BIT[i] += v;
}
 
ll get(int i) {
  ll v = 0;
  for (; i > 0; i -= i&-i) v += BIT[i];
  return v;
}
 
void dfs(int u, int p) {
  in[u] = t++;
  for (int v : ve[u])
    if (v != p)
      dfs(v, u);
  out[u] = t++;
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++)
    cin >> val[i];
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    ve[u].pb(v);
    ve[v].pb(u);
  }
  dfs(1, 1);
  for (int i = 1; i <= n; i++) {
    up(in[i], val[i]);
    up(out[i]+1, -val[i]);
  }
  while (q--) {
    int a, s;
    ll x;
    cin >> a >> s;
    if (a == 1) {
      cin >> x;
      up(in[s], -val[s]);
      up(out[s]+1, val[s]);
      up(in[s], x);
      up(out[s]+1, -x);
      val[s] = x;
    }
    else cout << get(in[s]) << '\n';
  }
  return 0;
}