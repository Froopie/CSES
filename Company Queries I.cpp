#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 2e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
vector<int> ve[MAXN];
int bz, level[MAXN], sqrtP[MAXN], p[MAXN];
 
void dfs(int u, int sqrtp, int l) {
  level[u] = l;
  sqrtP[u] = sqrtp;
  int newp = sqrtp;
  if (l%bz == 0)
    newp = u;
  for (int v : ve[u])
    dfs(v, newp, l+1);
}
 
int gets(int u, int k) {
  int L = level[u]-k;
  if (L < 1) return -1;
  while (level[sqrtP[u]] >= L)
    u = sqrtP[u];
  while (level[u] > L)
    u = p[u];
  return u;
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  bz = sqrt(n);
  for (int i = 2; i <= n; i++) {
    int u;
    cin >> u;
    p[i] = u;
    ve[u].pb(i);
  }
  dfs(1,0,1);
  while (q--) {
    int x, k;
    cin >> x >> k;
    cout << gets(x,k) << '\n';
  }
  return 0;
}
