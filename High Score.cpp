#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
#define x first
#define y second
const int MAXN = 2500 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
int n, m;
ll score[MAXN];
vector<int> ve[MAXN];
 
struct edge{
  int u, v;
  ll x;
  edge(int a, int b, ll c) {
    u = a; v = b; x = c;
  }
};
 
vector<edge> edges;
 
bool cyc, vis[MAXN][2], inc[MAXN];
 
void dfs(int u, bool k) {
  if (inc[u]) k = 1;
  if (u == n && k)
    cyc = 1;
  if (vis[u][k]) return;
  vis[u][k] = 1;
  for (int v : ve[u])
    dfs(v,k);
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  while (m--) {
    int a, b;
    ll x;
    cin >> a >> b >> x;
    edges.pb(edge(a,b,-x));
    ve[a].pb(b);
  }
  for (int i = 1; i <= 2500; i++)
    score[i] = (1LL<<60);
  score[1] = 0;
  for (int i = 1; i <= n+1; i++)
    for (auto k : edges)
      score[k.v] = min(score[k.v], score[k.u]+k.x);
  for (auto k : edges) {
    if (score[k.v] > score[k.u]+k.x)
      inc[k.v] = 1;
    score[k.v] = min(score[k.v], score[k.u]+k.x);
  }
  dfs(1,0);
  if (cyc) {
    cout << -1;
    return 0;
  }
  cout << -score[n];
  return 0;
}