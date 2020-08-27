#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 1e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
struct mat{
  int n, m;
  vector<vector<ll>> a;
  mat(int c, int b){
    n = c; m = b;
    vector<ll> ve(m,-1);
    for (int i = 0; i < n; i++)
      a.pb(ve);
  }
  mat operator*(mat b) {
    mat M = mat(n,b.m);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < b.m; j++) {
        M.a[i][j] = -1;
        for (int k = 0; k < b.m; k++) {
          if (M.a[i][j] == -1 && a[i][k] != -1 && b.a[k][j] != -1)
            M.a[i][j] = a[i][k]+b.a[k][j];
          if (a[i][k] != -1 && b.a[k][j] != -1)
            M.a[i][j] = min(M.a[i][j], a[i][k]+b.a[k][j]);
        }
      }
    return M;
  }
};
 
mat id(int n, int m) {
  mat A = mat(n,m);
  for (int i = 0; i < min(n,m); i++)
    A.a[i][i] = 1;
  return A;
}
 
mat po(mat A, ll p) {
  if (p == 1) return A;
  mat x = po(A, (p>>1));
  x = (x*x);
  if ((p&1)) x = x*A;
  return x;
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  mat A = mat(n,n);
  while (m--) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    if (A.a[u-1][v-1] == -1) A.a[u-1][v-1] = w;
    A.a[u-1][v-1] = min(A.a[u-1][v-1], w);
  }
  A = po(A,k);
  cout << A.a[0][n-1];
  return 0;
}