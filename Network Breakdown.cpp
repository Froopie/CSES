#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
#define all(c) c.begin(), c.end()
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define vi vector<int>
#define vll vector<ll>
#define ff first
#define ss second
using ll = long long;
const int MAXN = 1e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline ll rand(ll a, ll b) {ll c = rng(); return a+((ll)abs(c))%(b-a+1);}
 
int par[MAXN];
bool vis[MAXN];
 
void init(int n) {
  for (int i = 1; i <= n; i++)
    par[i] = i;
}
 
int find(int u) {
  return par[u] = (par[u] == u? u : find(par[u]));
}
 
int cnt;
set<int> se[MAXN];
 
void unio(int u, int v) {
  u = find(u);
  v = find(v);
  cnt -= (u != v);
  par[v] = u;
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  init(n);
  cnt = n;
  vector<pii> edges(m), queries(q);
  for (int i = 0; i < m; i++)
    cin >> edges[i].ff >> edges[i].ss;
  for (int i = 0; i < q; i++) {
    cin >> queries[i].ff >> queries[i].ss;
    se[queries[i].ff].insert(queries[i].ss);
    se[queries[i].ss].insert(queries[i].ff);
  }
  for (auto k : edges)
    if (se[k.ff].find(k.ss) == se[k.ff].end())
      unio(k.ff,k.ss);
  vector<int> ans;
  for (int i = q-1; i >= 0; i--) {
    ans.pb(cnt);
    unio(queries[i].ff,queries[i].ss);
  }
  reverse(all(ans));
  for (int i : ans) cout << i << ' ';
  return 0;
}
