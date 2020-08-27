#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 1e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
struct mat{
  int a[6][6];
  mat() {
    memset(a, 0, sizeof a);
    for (int i = 0; i < 6; i++)
      a[0][i] = 1;
    for (int i = 1; i < 6; i++)
      a[i][i-1] = 1;
  }
  mat operator*(const mat &m) {
    mat ret;
    for (int i = 0; i < 6; i++)
      for (int j = 0; j < 6; j++) {
        int &sum = ret.a[i][j];
        sum = 0;
        for (int k = 0; k < 6; k++)
        sum = (1LL*sum+m.a[i][k]*1LL*a[k][j])%mod;
      }
    return ret;
  }
};
 
mat po(mat m, ll p) {
  if (p == 1) return m;
  mat t = po(m, p>>1);
  t = t*t;
  if (p&1) t = t*m;
  return t;
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n;
  int h[] = {1, 2, 4, 8, 16, 32};
  cin >> n;
  if (n <= 6) cout << h[n-1];
  else {
    mat m;
    m = po(m, n-6);
    ll ans = 0;
    for (int i = 0; i < 6; i++)
      ans = (ans+h[5-i]*1LL*m.a[0][i])%mod;
    cout << ans;
  }
  return 0;
}