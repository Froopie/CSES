#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 1e3 + 5, MAXM = 1e2 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
int n, m;
string s;
vector<int> f;
ll dp[MAXM][MAXN], po[MAXN];
 
ll rec(int i, int border) {
  if (border == m)
    return po[n-i];
  if (i == n) return 0;
  ll &ret = dp[border][i];
  if (ret != -1) return ret;
  ret = 0;
  for (char a = 'A'; a <= 'Z'; a++) {
    int b = border;
    while (b && s[b] != a)
      b = f[b-1];
    if (s[b] == a)
      b++;
    if (border == m) b = m;
    ret = (ret+rec(i+1, b))%mod;
  }
  return ret;
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  po[0] = 1;
  for (int i = 1; i < MAXN; i++)
    po[i] = (po[i-1]*26LL)%mod;
  cin >> n >> s;
  m = s.size();
  f.resize(m);
  int border = 0;
  f[0] = 0;
  for (int i = 1; i < (int)s.size(); i++) {
    while (border && s[border] != s[i])
      border = f[border-1];
    if (s[border] == s[i])
      border++;
    f[i] = border;
  }
  memset(dp, -1, sizeof dp);
  cout << rec(0, 0);
  return 0;
}