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
    vector<ll> ve(m);
    for (int i = 0; i < n; i++)
      a.pb(ve);
  }
  mat operator*(mat b) {
    mat M = mat(n,b.m);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < b.m; j++)
        for (int k = 0; k < b.m; k++) {
          M.a[i][j] += (a[i][k]*b.a[k][j])%mod;
          M.a[i][j] %= mod;
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
  if (!p) return id(A.n,A.m);
  mat x = po(A, (p>>1));
  x = (x*x);
  if ((p&1)) x = x*A;
  return x;
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n;
  cin >> n;
  mat A = mat(2,2);
  A.a[0][0] = A.a[1][0] = A.a[0][1] = 1;
  mat B = mat(2,2);
  B.a[0][0] = 1;
  if (n == 0) {
    cout << 0;
    return 0;
  }
  cout << (po(A, n-1)*B).a[0][0];
  return 0;
}